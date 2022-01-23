/*
 * Transaction.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: mad
 */

#include <mmx/Transaction.hxx>
#include <mmx/write_bytes.h>


namespace mmx {

hash_t TransactionBase::calc_hash() const {
	return id;
}

uint64_t TransactionBase::calc_cost(std::shared_ptr<const ChainParams> params) const {
	return 0;
}

void Transaction::finalize() {
	id = calc_hash();
}

vnx::bool_t Transaction::is_valid() const {
	return calc_hash() == id;
}

hash_t Transaction::calc_hash() const
{
	std::vector<uint8_t> buffer;
	vnx::VectorOutputStream stream(&buffer);
	vnx::OutputBuffer out(&stream);

	buffer.reserve(4 * 1024);

	// TODO: write_bytes(out, get_type_hash());
	write_bytes(out, version);

	for(const auto& tx : inputs) {
		write_bytes(out, tx);
	}
	for(const auto& tx : outputs) {
		write_bytes(out, tx);
	}
	for(const auto& op : execute) {
		write_bytes(out, op ? op->calc_hash() : hash_t());
	}
	write_bytes(out, deploy ? deploy->calc_hash() : hash_t());

	out.flush();

	return hash_t(buffer);
}

std::shared_ptr<const Solution> Transaction::get_solution(const uint32_t& index) const
{
	if(index < solutions.size()) {
		return solutions[index];
	}
	return nullptr;
}

uint64_t Transaction::calc_cost(std::shared_ptr<const ChainParams> params) const
{
	if(!params) {
		throw std::logic_error("!params");
	}
	uint64_t fee = (inputs.size() + outputs.size()) * params->min_txfee_io;

	for(const auto& op : execute) {
		if(op) {
			fee += op->calc_min_fee(params);
		}
	}
	for(const auto& sol : solutions) {
		if(sol) {
			fee += sol->calc_min_fee(params);
		}
	}
	if(deploy) {
		fee += deploy->calc_min_fee(params);
	}
	return fee;
}


} // mmx
