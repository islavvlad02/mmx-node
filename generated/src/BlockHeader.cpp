
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/BlockHeader_calc_hash.hxx>
#include <mmx/BlockHeader_calc_hash_return.hxx>
#include <mmx/BlockHeader_get_header.hxx>
#include <mmx/BlockHeader_get_header_return.hxx>
#include <mmx/BlockHeader_is_valid.hxx>
#include <mmx/BlockHeader_is_valid_return.hxx>
#include <mmx/BlockHeader_validate.hxx>
#include <mmx/BlockHeader_validate_return.hxx>
#include <mmx/ProofOfSpace.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/bls_signature_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/uint128.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 BlockHeader::VNX_TYPE_HASH(0xcaae941a2fc712a6ull);
const vnx::Hash64 BlockHeader::VNX_CODE_HASH(0x13f945838017d0aeull);

vnx::Hash64 BlockHeader::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string BlockHeader::get_type_name() const {
	return "mmx.BlockHeader";
}

const vnx::TypeCode* BlockHeader::get_type_code() const {
	return mmx::vnx_native_type_code_BlockHeader;
}

std::shared_ptr<BlockHeader> BlockHeader::create() {
	return std::make_shared<BlockHeader>();
}

std::shared_ptr<vnx::Value> BlockHeader::clone() const {
	return std::make_shared<BlockHeader>(*this);
}

void BlockHeader::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void BlockHeader::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void BlockHeader::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_BlockHeader;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, hash);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, prev);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, height);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, nonce);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, time_diff);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, space_diff);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, weight);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, total_weight);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, netspace_ratio);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, vdf_iters);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, vdf_output);
	_visitor.type_field(_type_code->fields[12], 12); vnx::accept(_visitor, proof);
	_visitor.type_field(_type_code->fields[13], 13); vnx::accept(_visitor, tx_base);
	_visitor.type_field(_type_code->fields[14], 14); vnx::accept(_visitor, static_cost);
	_visitor.type_field(_type_code->fields[15], 15); vnx::accept(_visitor, total_cost);
	_visitor.type_field(_type_code->fields[16], 16); vnx::accept(_visitor, tx_count);
	_visitor.type_field(_type_code->fields[17], 17); vnx::accept(_visitor, tx_fees);
	_visitor.type_field(_type_code->fields[18], 18); vnx::accept(_visitor, tx_hash);
	_visitor.type_field(_type_code->fields[19], 19); vnx::accept(_visitor, farmer_sig);
	_visitor.type_field(_type_code->fields[20], 20); vnx::accept(_visitor, content_hash);
	_visitor.type_end(*_type_code);
}

void BlockHeader::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.BlockHeader\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"hash\": "; vnx::write(_out, hash);
	_out << ", \"prev\": "; vnx::write(_out, prev);
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << ", \"nonce\": "; vnx::write(_out, nonce);
	_out << ", \"time_diff\": "; vnx::write(_out, time_diff);
	_out << ", \"space_diff\": "; vnx::write(_out, space_diff);
	_out << ", \"weight\": "; vnx::write(_out, weight);
	_out << ", \"total_weight\": "; vnx::write(_out, total_weight);
	_out << ", \"netspace_ratio\": "; vnx::write(_out, netspace_ratio);
	_out << ", \"vdf_iters\": "; vnx::write(_out, vdf_iters);
	_out << ", \"vdf_output\": "; vnx::write(_out, vdf_output);
	_out << ", \"proof\": "; vnx::write(_out, proof);
	_out << ", \"tx_base\": "; vnx::write(_out, tx_base);
	_out << ", \"static_cost\": "; vnx::write(_out, static_cost);
	_out << ", \"total_cost\": "; vnx::write(_out, total_cost);
	_out << ", \"tx_count\": "; vnx::write(_out, tx_count);
	_out << ", \"tx_fees\": "; vnx::write(_out, tx_fees);
	_out << ", \"tx_hash\": "; vnx::write(_out, tx_hash);
	_out << ", \"farmer_sig\": "; vnx::write(_out, farmer_sig);
	_out << ", \"content_hash\": "; vnx::write(_out, content_hash);
	_out << "}";
}

void BlockHeader::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object BlockHeader::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.BlockHeader";
	_object["version"] = version;
	_object["hash"] = hash;
	_object["prev"] = prev;
	_object["height"] = height;
	_object["nonce"] = nonce;
	_object["time_diff"] = time_diff;
	_object["space_diff"] = space_diff;
	_object["weight"] = weight;
	_object["total_weight"] = total_weight;
	_object["netspace_ratio"] = netspace_ratio;
	_object["vdf_iters"] = vdf_iters;
	_object["vdf_output"] = vdf_output;
	_object["proof"] = proof;
	_object["tx_base"] = tx_base;
	_object["static_cost"] = static_cost;
	_object["total_cost"] = total_cost;
	_object["tx_count"] = tx_count;
	_object["tx_fees"] = tx_fees;
	_object["tx_hash"] = tx_hash;
	_object["farmer_sig"] = farmer_sig;
	_object["content_hash"] = content_hash;
	return _object;
}

void BlockHeader::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "content_hash") {
			_entry.second.to(content_hash);
		} else if(_entry.first == "farmer_sig") {
			_entry.second.to(farmer_sig);
		} else if(_entry.first == "hash") {
			_entry.second.to(hash);
		} else if(_entry.first == "height") {
			_entry.second.to(height);
		} else if(_entry.first == "netspace_ratio") {
			_entry.second.to(netspace_ratio);
		} else if(_entry.first == "nonce") {
			_entry.second.to(nonce);
		} else if(_entry.first == "prev") {
			_entry.second.to(prev);
		} else if(_entry.first == "proof") {
			_entry.second.to(proof);
		} else if(_entry.first == "space_diff") {
			_entry.second.to(space_diff);
		} else if(_entry.first == "static_cost") {
			_entry.second.to(static_cost);
		} else if(_entry.first == "time_diff") {
			_entry.second.to(time_diff);
		} else if(_entry.first == "total_cost") {
			_entry.second.to(total_cost);
		} else if(_entry.first == "total_weight") {
			_entry.second.to(total_weight);
		} else if(_entry.first == "tx_base") {
			_entry.second.to(tx_base);
		} else if(_entry.first == "tx_count") {
			_entry.second.to(tx_count);
		} else if(_entry.first == "tx_fees") {
			_entry.second.to(tx_fees);
		} else if(_entry.first == "tx_hash") {
			_entry.second.to(tx_hash);
		} else if(_entry.first == "vdf_iters") {
			_entry.second.to(vdf_iters);
		} else if(_entry.first == "vdf_output") {
			_entry.second.to(vdf_output);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		} else if(_entry.first == "weight") {
			_entry.second.to(weight);
		}
	}
}

vnx::Variant BlockHeader::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "hash") {
		return vnx::Variant(hash);
	}
	if(_name == "prev") {
		return vnx::Variant(prev);
	}
	if(_name == "height") {
		return vnx::Variant(height);
	}
	if(_name == "nonce") {
		return vnx::Variant(nonce);
	}
	if(_name == "time_diff") {
		return vnx::Variant(time_diff);
	}
	if(_name == "space_diff") {
		return vnx::Variant(space_diff);
	}
	if(_name == "weight") {
		return vnx::Variant(weight);
	}
	if(_name == "total_weight") {
		return vnx::Variant(total_weight);
	}
	if(_name == "netspace_ratio") {
		return vnx::Variant(netspace_ratio);
	}
	if(_name == "vdf_iters") {
		return vnx::Variant(vdf_iters);
	}
	if(_name == "vdf_output") {
		return vnx::Variant(vdf_output);
	}
	if(_name == "proof") {
		return vnx::Variant(proof);
	}
	if(_name == "tx_base") {
		return vnx::Variant(tx_base);
	}
	if(_name == "static_cost") {
		return vnx::Variant(static_cost);
	}
	if(_name == "total_cost") {
		return vnx::Variant(total_cost);
	}
	if(_name == "tx_count") {
		return vnx::Variant(tx_count);
	}
	if(_name == "tx_fees") {
		return vnx::Variant(tx_fees);
	}
	if(_name == "tx_hash") {
		return vnx::Variant(tx_hash);
	}
	if(_name == "farmer_sig") {
		return vnx::Variant(farmer_sig);
	}
	if(_name == "content_hash") {
		return vnx::Variant(content_hash);
	}
	return vnx::Variant();
}

void BlockHeader::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "hash") {
		_value.to(hash);
	} else if(_name == "prev") {
		_value.to(prev);
	} else if(_name == "height") {
		_value.to(height);
	} else if(_name == "nonce") {
		_value.to(nonce);
	} else if(_name == "time_diff") {
		_value.to(time_diff);
	} else if(_name == "space_diff") {
		_value.to(space_diff);
	} else if(_name == "weight") {
		_value.to(weight);
	} else if(_name == "total_weight") {
		_value.to(total_weight);
	} else if(_name == "netspace_ratio") {
		_value.to(netspace_ratio);
	} else if(_name == "vdf_iters") {
		_value.to(vdf_iters);
	} else if(_name == "vdf_output") {
		_value.to(vdf_output);
	} else if(_name == "proof") {
		_value.to(proof);
	} else if(_name == "tx_base") {
		_value.to(tx_base);
	} else if(_name == "static_cost") {
		_value.to(static_cost);
	} else if(_name == "total_cost") {
		_value.to(total_cost);
	} else if(_name == "tx_count") {
		_value.to(tx_count);
	} else if(_name == "tx_fees") {
		_value.to(tx_fees);
	} else if(_name == "tx_hash") {
		_value.to(tx_hash);
	} else if(_name == "farmer_sig") {
		_value.to(farmer_sig);
	} else if(_name == "content_hash") {
		_value.to(content_hash);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const BlockHeader& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, BlockHeader& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* BlockHeader::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> BlockHeader::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.BlockHeader";
	type_code->type_hash = vnx::Hash64(0xcaae941a2fc712a6ull);
	type_code->code_hash = vnx::Hash64(0x13f945838017d0aeull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::BlockHeader);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<BlockHeader>(); };
	type_code->methods.resize(4);
	type_code->methods[0] = ::mmx::BlockHeader_calc_hash::static_get_type_code();
	type_code->methods[1] = ::mmx::BlockHeader_get_header::static_get_type_code();
	type_code->methods[2] = ::mmx::BlockHeader_is_valid::static_get_type_code();
	type_code->methods[3] = ::mmx::BlockHeader_validate::static_get_type_code();
	type_code->fields.resize(21);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "hash";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "prev";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "height";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 8;
		field.name = "nonce";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 8;
		field.name = "time_diff";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[6];
		field.data_size = 8;
		field.name = "space_diff";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "weight";
		field.code = {11, 16, 1};
	}
	{
		auto& field = type_code->fields[8];
		field.is_extended = true;
		field.name = "total_weight";
		field.code = {11, 16, 1};
	}
	{
		auto& field = type_code->fields[9];
		field.data_size = 4;
		field.name = "netspace_ratio";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[10];
		field.data_size = 8;
		field.name = "vdf_iters";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[11];
		field.is_extended = true;
		field.name = "vdf_output";
		field.code = {11, 2, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[12];
		field.is_extended = true;
		field.name = "proof";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[13];
		field.is_extended = true;
		field.name = "tx_base";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[14];
		field.data_size = 4;
		field.name = "static_cost";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[15];
		field.data_size = 4;
		field.name = "total_cost";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[16];
		field.data_size = 4;
		field.name = "tx_count";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[17];
		field.data_size = 4;
		field.name = "tx_fees";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[18];
		field.is_extended = true;
		field.name = "tx_hash";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[19];
		field.is_extended = true;
		field.name = "farmer_sig";
		field.code = {33, 11, 96, 1};
	}
	{
		auto& field = type_code->fields[20];
		field.is_extended = true;
		field.name = "content_hash";
		field.code = {11, 32, 1};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> BlockHeader::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
		case 0xc525b15a3f7ee317ull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_calc_hash>(_method);
			auto _return_value = ::mmx::BlockHeader_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash();
			return _return_value;
		}
		case 0xd7c88d66a260d84aull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_get_header>(_method);
			auto _return_value = ::mmx::BlockHeader_get_header_return::create();
			_return_value->_ret_0 = get_header();
			return _return_value;
		}
		case 0xee0825f87d03a5ebull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_is_valid>(_method);
			auto _return_value = ::mmx::BlockHeader_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
		case 0xcfb7b60e776d1aaeull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_validate>(_method);
			auto _return_value = ::mmx::BlockHeader_validate_return::create();
			validate();
			return _return_value;
		}
	}
	return nullptr;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::BlockHeader& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.nonce, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.time_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[6]) {
			vnx::read_value(_buf + _field->offset, value.space_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[9]) {
			vnx::read_value(_buf + _field->offset, value.netspace_ratio, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[10]) {
			vnx::read_value(_buf + _field->offset, value.vdf_iters, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[14]) {
			vnx::read_value(_buf + _field->offset, value.static_cost, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[15]) {
			vnx::read_value(_buf + _field->offset, value.total_cost, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[16]) {
			vnx::read_value(_buf + _field->offset, value.tx_count, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[17]) {
			vnx::read_value(_buf + _field->offset, value.tx_fees, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.hash, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.prev, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.weight, type_code, _field->code.data()); break;
			case 8: vnx::read(in, value.total_weight, type_code, _field->code.data()); break;
			case 11: vnx::read(in, value.vdf_output, type_code, _field->code.data()); break;
			case 12: vnx::read(in, value.proof, type_code, _field->code.data()); break;
			case 13: vnx::read(in, value.tx_base, type_code, _field->code.data()); break;
			case 18: vnx::read(in, value.tx_hash, type_code, _field->code.data()); break;
			case 19: vnx::read(in, value.farmer_sig, type_code, _field->code.data()); break;
			case 20: vnx::read(in, value.content_hash, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::BlockHeader& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_BlockHeader;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::BlockHeader>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(60);
	vnx::write_value(_buf + 0, value.version);
	vnx::write_value(_buf + 4, value.height);
	vnx::write_value(_buf + 8, value.nonce);
	vnx::write_value(_buf + 16, value.time_diff);
	vnx::write_value(_buf + 24, value.space_diff);
	vnx::write_value(_buf + 32, value.netspace_ratio);
	vnx::write_value(_buf + 36, value.vdf_iters);
	vnx::write_value(_buf + 44, value.static_cost);
	vnx::write_value(_buf + 48, value.total_cost);
	vnx::write_value(_buf + 52, value.tx_count);
	vnx::write_value(_buf + 56, value.tx_fees);
	vnx::write(out, value.hash, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.prev, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.weight, type_code, type_code->fields[7].code.data());
	vnx::write(out, value.total_weight, type_code, type_code->fields[8].code.data());
	vnx::write(out, value.vdf_output, type_code, type_code->fields[11].code.data());
	vnx::write(out, value.proof, type_code, type_code->fields[12].code.data());
	vnx::write(out, value.tx_base, type_code, type_code->fields[13].code.data());
	vnx::write(out, value.tx_hash, type_code, type_code->fields[18].code.data());
	vnx::write(out, value.farmer_sig, type_code, type_code->fields[19].code.data());
	vnx::write(out, value.content_hash, type_code, type_code->fields[20].code.data());
}

void read(std::istream& in, ::mmx::BlockHeader& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::BlockHeader& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::BlockHeader& value) {
	value.accept(visitor);
}

} // vnx
