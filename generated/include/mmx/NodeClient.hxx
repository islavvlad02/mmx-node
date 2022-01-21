
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Node_CLIENT_HXX_
#define INCLUDE_mmx_Node_CLIENT_HXX_

#include <vnx/Client.h>
#include <mmx/Block.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Contract.hxx>
#include <mmx/NetworkInfo.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/stxo_entry_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/txio_key_t.hxx>
#include <mmx/txo_info_t.hxx>
#include <mmx/utxo_entry_t.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>


namespace mmx {

class NodeClient : public vnx::Client {
public:
	NodeClient(const std::string& service_name);
	
	NodeClient(vnx::Hash64 service_addr);
	
	::vnx::Object vnx_get_config_object();
	
	::vnx::Variant vnx_get_config(const std::string& name = "");
	
	void vnx_set_config_object(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config_object_async(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	void vnx_set_config_async(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	::vnx::TypeCode vnx_get_type_code();
	
	std::shared_ptr<const ::vnx::ModuleInfo> vnx_get_module_info();
	
	void vnx_restart();
	
	void vnx_restart_async();
	
	void vnx_stop();
	
	void vnx_stop_async();
	
	vnx::bool_t vnx_self_test();
	
	std::shared_ptr<const ::mmx::ChainParams> get_params();
	
	std::shared_ptr<const ::mmx::NetworkInfo> get_network_info();
	
	uint32_t get_height();
	
	vnx::optional<uint32_t> get_synced_height();
	
	std::shared_ptr<const ::mmx::Block> get_block(const ::mmx::hash_t& hash = ::mmx::hash_t());
	
	std::shared_ptr<const ::mmx::Block> get_block_at(const uint32_t& height = 0);
	
	std::shared_ptr<const ::mmx::BlockHeader> get_header(const ::mmx::hash_t& hash = ::mmx::hash_t());
	
	std::shared_ptr<const ::mmx::BlockHeader> get_header_at(const uint32_t& height = 0);
	
	vnx::optional<::mmx::hash_t> get_block_hash(const uint32_t& height = 0);
	
	vnx::optional<::mmx::txo_info_t> get_txo_info(const ::mmx::txio_key_t& key = ::mmx::txio_key_t());
	
	std::vector<vnx::optional<::mmx::txo_info_t>> get_txo_infos(const std::vector<::mmx::txio_key_t>& keys = {});
	
	vnx::optional<uint32_t> get_tx_height(const ::mmx::hash_t& id = ::mmx::hash_t());
	
	std::vector<::mmx::hash_t> get_tx_ids_at(const uint32_t& height = 0);
	
	void add_block(std::shared_ptr<const ::mmx::Block> block = nullptr);
	
	void add_block_async(std::shared_ptr<const ::mmx::Block> block = nullptr);
	
	void add_transaction(std::shared_ptr<const ::mmx::Transaction> tx = nullptr);
	
	void add_transaction_async(std::shared_ptr<const ::mmx::Transaction> tx = nullptr);
	
	std::shared_ptr<const ::mmx::Contract> get_contract(const ::mmx::addr_t& address = ::mmx::addr_t());
	
	std::vector<std::shared_ptr<const ::mmx::Contract>> get_contracts(const std::vector<::mmx::addr_t>& addresses = {});
	
	std::map<::mmx::addr_t, std::shared_ptr<const ::mmx::Contract>> get_contracts_owned(const std::vector<::mmx::addr_t>& owners = {});
	
	std::shared_ptr<const ::mmx::Transaction> get_transaction(const ::mmx::hash_t& id = ::mmx::hash_t(), const vnx::bool_t& include_pending = 0);
	
	std::vector<std::shared_ptr<const ::mmx::Transaction>> get_transactions(const std::vector<::mmx::hash_t>& ids = {});
	
	std::vector<::mmx::tx_entry_t> get_history_for(const std::vector<::mmx::addr_t>& addresses = {}, const int32_t& since = 0);
	
	uint64_t get_balance(const ::mmx::addr_t& address = ::mmx::addr_t(), const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	uint64_t get_total_balance(const std::vector<::mmx::addr_t>& addresses = {}, const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	std::map<::mmx::addr_t, uint64_t> get_total_balances(const std::vector<::mmx::addr_t>& addresses = {});
	
	uint64_t get_total_supply(const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	std::vector<::mmx::utxo_entry_t> get_utxo_list(const std::vector<::mmx::addr_t>& addresses = {});
	
	std::vector<::mmx::stxo_entry_t> get_stxo_list(const std::vector<::mmx::addr_t>& addresses = {});
	
	void start_sync(const vnx::bool_t& force = 0);
	
	void start_sync_async(const vnx::bool_t& force = 0);
	
	std::shared_ptr<const ::vnx::addons::HttpResponse> http_request(std::shared_ptr<const ::vnx::addons::HttpRequest> request = nullptr, const std::string& sub_path = "");
	
	std::shared_ptr<const ::vnx::addons::HttpData> http_request_chunk(std::shared_ptr<const ::vnx::addons::HttpRequest> request = nullptr, const std::string& sub_path = "", const int64_t& offset = 0, const int64_t& max_bytes = 0);
	
};


} // namespace mmx

#endif // INCLUDE_mmx_Node_CLIENT_HXX_
