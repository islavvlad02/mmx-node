/*
 * Wallet.cpp
 *
 *  Created on: Dec 11, 2021
 *      Author: mad
 */

#include <mmx/Wallet.h>
#include <mmx/utxo_t.hpp>
#include <mmx/utxo_entry_t.hpp>
#include <mmx/stxo_entry_t.hpp>
#include <mmx/contract/Token.hxx>
#include <mmx/solution/PubKey.hxx>
#include <mmx/utils.h>

#include <vnx/vnx.h>
#include <algorithm>


namespace mmx {

Wallet::Wallet(const std::string& _vnx_name)
	:	WalletBase(_vnx_name)
{
}

void Wallet::init()
{
	vnx::open_pipe(vnx_name, this, 1000);
}

void Wallet::main()
{
	params = get_params();

	http = std::make_shared<vnx::addons::HttpInterface<Wallet>>(this, vnx_name);
	add_async_client(http);

	for(auto file_path : key_files)
	{
		file_path = storage_path + file_path;

		if(auto key_file = vnx::read_from_file<KeyFile>(file_path))
		{
			if(enable_bls) {
				bls_wallets.push_back(std::make_shared<BLS_Wallet>(key_file, 11337));
			} else {
				bls_wallets.push_back(nullptr);
			}
			wallets.push_back(std::make_shared<ECDSA_Wallet>(key_file, params, num_addresses));
		}
		else {
			wallets.push_back(nullptr);
			bls_wallets.push_back(nullptr);
			log(ERROR) << "Failed to read wallet '" << file_path << "'";
		}
	}

	node = std::make_shared<NodeClient>(node_server);

	Super::main();
}

std::shared_ptr<ECDSA_Wallet> Wallet::get_wallet(const uint32_t& index) const
{
	if(index >= wallets.size()) {
		throw std::logic_error("invalid wallet index: " + std::to_string(index));
	}
	if(auto wallet = wallets[index]) {
		return wallet;
	}
	throw std::logic_error("no such wallet");
}

hash_t Wallet::send(const uint32_t& index, const uint64_t& amount, const addr_t& dst_addr, const addr_t& currency, const spend_options_t& options) const
{
	if(amount == 0) {
		throw std::logic_error("amount cannot be zero");
	}
	if(dst_addr == addr_t()) {
		throw std::logic_error("dst_addr cannot be zero");
	}
	const auto wallet = get_wallet(index);
	get_utxo_list(index);	// update utxo_cache

	auto tx = wallet->send(amount, dst_addr, currency, options);

	node->add_transaction(tx);
	wallet->update_from(tx);

	log(INFO) << "Sent " << amount << " with fee " << tx->calc_min_fee(params) << " to " << dst_addr << " (" << tx->id << ")";
	return tx->id;
}

hash_t Wallet::send_from(	const uint32_t& index, const uint64_t& amount,
							const addr_t& dst_addr, const addr_t& src_addr,
							const addr_t& currency, const spend_options_t& options) const
{
	if(amount == 0) {
		throw std::logic_error("amount cannot be zero");
	}
	if(dst_addr == addr_t()) {
		throw std::logic_error("dst_addr cannot be zero");
	}
	const auto wallet = get_wallet(index);
	get_utxo_list(index);	// update utxo_cache

	auto src_owner = src_addr;
	if(auto contract = node->get_contract(src_addr)) {
		if(auto owner = contract->get_owner()) {
			src_owner = *owner;
		} else {
			throw std::logic_error("contract has no owner");
		}
	}
	auto tx = wallet->send_from(amount, dst_addr, src_addr, src_owner,
								node->get_utxo_list({src_addr}, options.min_confirm), currency, options);

	node->add_transaction(tx);
	wallet->update_from(tx);

	log(INFO) << "Sent " << amount << " with fee " << tx->calc_min_fee(params) << " to " << dst_addr << " (" << tx->id << ")";
	return tx->id;
}

hash_t Wallet::mint(const uint32_t& index, const uint64_t& amount, const addr_t& dst_addr, const addr_t& currency, const spend_options_t& options) const
{
	if(amount == 0) {
		throw std::logic_error("amount cannot be zero");
	}
	if(dst_addr == addr_t()) {
		throw std::logic_error("dst_addr cannot be zero");
	}
	const auto token = std::dynamic_pointer_cast<const contract::Token>(node->get_contract(currency));
	if(!token) {
		throw std::logic_error("no such currency");
	}
	if(!token->owner) {
		throw std::logic_error("token has no owner");
	}
	const auto wallet = get_wallet(index);
	get_utxo_list(index);	// update utxo_cache

	auto tx = wallet->mint(amount, dst_addr, currency, *token->owner, options);

	node->add_transaction(tx);
	wallet->update_from(tx);

	log(INFO) << "Minted " << amount << " with fee " << tx->calc_min_fee(params) << " to " << dst_addr << " (" << tx->id << ")";
	return tx->id;
}

hash_t Wallet::deploy(const uint32_t& index, std::shared_ptr<const Contract> contract, const spend_options_t& options) const
{
	if(!contract) {
		throw std::logic_error("contract cannot be null");
	}
	const auto wallet = get_wallet(index);
	get_utxo_list(index);	// update utxo_cache

	auto tx = wallet->deploy(contract, options);

	node->add_transaction(tx);
	wallet->update_from(tx);

	log(INFO) << "Deployed " << contract->get_type_name() << " with fee " << tx->calc_min_fee(params) << " as " << addr_t(tx->id) << " (" << tx->id << ")";
	return tx->id;
}

std::shared_ptr<const Transaction> Wallet::sign_off(const uint32_t& index, std::shared_ptr<const Transaction> tx) const
{
	const auto wallet = get_wallet(index);

	std::unordered_map<txio_key_t, utxo_t> utxo_map;
	for(const auto& entry : wallet->utxo_cache) {
		utxo_map[entry.key] = entry.output;
	}
	auto copy = vnx::clone(tx);
	wallet->sign_off(copy, utxo_map);
	return copy;
}

std::vector<utxo_entry_t> Wallet::get_utxo_list(const uint32_t& index, const uint32_t& min_confirm) const
{
	const auto wallet = get_wallet(index);
	const auto now = vnx::get_wall_time_millis();

	if(!wallet->last_utxo_update || now - wallet->last_utxo_update > utxo_timeout_ms)
	{
		const auto height = node->get_height();
		const auto all_utxo = node->get_utxo_list(wallet->get_all_addresses(), 1);
		wallet->update_cache(all_utxo, height);
		wallet->last_utxo_update = now;

		log(INFO) << "Updated UTXO cache: " << wallet->utxo_cache.size() << " entries, " << wallet->utxo_change_cache.size() << " pending change";
	}
	if(min_confirm == 0) {
		return wallet->utxo_cache;
	}
	std::vector<utxo_entry_t> list;
	const auto height = node->get_height();
	for(const auto& entry : wallet->utxo_cache) {
		const auto utxo_height = entry.output.height;
		if(utxo_height <= height && (height - utxo_height) + 1 >= min_confirm) {
			list.push_back(entry);
		}
	}
	return list;
}

std::vector<utxo_entry_t> Wallet::get_utxo_list_for(const uint32_t& index, const addr_t& contract, const uint32_t& min_confirm) const
{
	std::vector<utxo_entry_t> res;
	for(const auto& entry : get_utxo_list(index, min_confirm)) {
		if(entry.output.contract == contract) {
			res.push_back(entry);
		}
	}
	return res;
}

std::vector<stxo_entry_t> Wallet::get_stxo_list(const uint32_t& index) const
{
	const auto wallet = get_wallet(index);
	return node->get_stxo_list(wallet->get_all_addresses());
}

std::vector<stxo_entry_t> Wallet::get_stxo_list_for(const uint32_t& index, const addr_t& contract) const
{
	std::vector<stxo_entry_t> res;
	for(const auto& entry : get_stxo_list(index)) {
		if(entry.output.contract == contract) {
			res.push_back(entry);
		}
	}
	return res;
}

std::vector<utxo_entry_t> Wallet::gather_utxos_for(const uint32_t& index, const uint64_t& amount, const addr_t& currency, const spend_options_t& options) const
{
	const auto wallet = get_wallet(index);
	get_utxo_list(index);	// update utxo_cache

	std::vector<tx_in_t> inputs;
	std::vector<utxo_entry_t> res;
	std::unordered_map<txio_key_t, utxo_t> spent_map;
	wallet->gather_inputs(inputs, wallet->utxo_cache, spent_map, amount, currency, options);
	for(const auto& in : inputs) {
		utxo_entry_t entry;
		entry.key = in.prev;
		entry.output = spent_map[in.prev];
		res.push_back(entry);
	}
	return res;
}

std::vector<tx_entry_t> Wallet::get_history(const uint32_t& index, const int32_t& since) const
{
	const auto wallet = get_wallet(index);
	return node->get_history_for(wallet->get_all_addresses(), since);
}

uint64_t Wallet::get_balance(const uint32_t& index, const addr_t& contract, const uint32_t& min_confirm) const
{
	uint64_t total = 0;
	for(const auto& entry : get_utxo_list(index, min_confirm)) {
		if(entry.output.contract == contract) {
			total += entry.output.amount;
		}
	}
	return total;
}

std::map<addr_t, uint64_t> Wallet::get_balances(const uint32_t& index, const uint32_t& min_confirm) const
{
	std::map<addr_t, uint64_t> amounts;
	for(const auto& entry : get_utxo_list(index, min_confirm)) {
		const auto& utxo = entry.output;
		amounts[utxo.contract] += utxo.amount;
	}
	return amounts;
}

std::map<addr_t, std::shared_ptr<const Contract>> Wallet::get_contracts(const uint32_t& index) const
{
	const auto wallet = get_wallet(index);
	return node->get_contracts_owned(wallet->get_all_addresses());
}

addr_t Wallet::get_address(const uint32_t& index, const uint32_t& offset) const
{
	const auto wallet = get_wallet(index);
	return wallet->get_address(offset);
}

std::vector<addr_t> Wallet::get_all_addresses(const int32_t& index) const
{
	if(index >= 0) {
		return get_wallet(index)->get_all_addresses();
	}
	std::vector<addr_t> list;
	for(const auto& wallet : wallets) {
		if(wallet) {
			const auto set = wallet->get_all_addresses();
			list.insert(list.end(), set.begin(), set.end());
		}
	}
	return list;
}

std::shared_ptr<const FarmerKeys> Wallet::get_farmer_keys(const uint32_t& index) const
{
	if(auto wallet = bls_wallets.at(index)) {
		return wallet->get_farmer_keys();
	}
	return nullptr;
}

std::vector<std::shared_ptr<const FarmerKeys>> Wallet::get_all_farmer_keys() const
{
	std::vector<std::shared_ptr<const FarmerKeys>> res;
	for(const auto& wallet : bls_wallets) {
		if(wallet) {
			res.push_back(wallet->get_farmer_keys());
		}
	}
	return res;
}

hash_t Wallet::get_master_seed(const uint32_t& index) const
{
	if(index >= key_files.size()) {
		throw std::logic_error("invalid wallet index");
	}
	if(auto key_file = vnx::read_from_file<KeyFile>(storage_path + key_files[index])) {
		return key_file->seed_value;
	}
	throw std::logic_error("failed to read key file");
}

void Wallet::http_request_async(std::shared_ptr<const vnx::addons::HttpRequest> request, const std::string& sub_path,
								const vnx::request_id_t& request_id) const
{
	http->http_request(request, sub_path, request_id);
}

void Wallet::http_request_chunk_async(	std::shared_ptr<const vnx::addons::HttpRequest> request, const std::string& sub_path,
										const int64_t& offset, const int64_t& max_bytes, const vnx::request_id_t& request_id) const
{
	throw std::logic_error("not implemented");
}


} // mmx
