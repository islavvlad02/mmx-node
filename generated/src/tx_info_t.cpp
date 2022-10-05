
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/tx_info_t.hxx>
#include <mmx/Contract.hxx>
#include <mmx/Operation.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/tx_note_e.hxx>
#include <mmx/txin_t.hxx>
#include <mmx/txout_t.hxx>
#include <mmx/uint128.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 tx_info_t::VNX_TYPE_HASH(0x44e4a710953f4785ull);
const vnx::Hash64 tx_info_t::VNX_CODE_HASH(0xfd57fcd9a977150ull);

vnx::Hash64 tx_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string tx_info_t::get_type_name() const {
	return "mmx.tx_info_t";
}

const vnx::TypeCode* tx_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_tx_info_t;
}

std::shared_ptr<tx_info_t> tx_info_t::create() {
	return std::make_shared<tx_info_t>();
}

std::shared_ptr<vnx::Value> tx_info_t::clone() const {
	return std::make_shared<tx_info_t>(*this);
}

void tx_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void tx_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void tx_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_tx_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, id);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, expires);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, did_fail);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, height);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, block);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, message);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, fee);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, cost);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, note);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, sender);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, inputs);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, outputs);
	_visitor.type_field(_type_code->fields[12], 12); vnx::accept(_visitor, operations);
	_visitor.type_field(_type_code->fields[13], 13); vnx::accept(_visitor, deployed);
	_visitor.type_field(_type_code->fields[14], 14); vnx::accept(_visitor, input_amounts);
	_visitor.type_field(_type_code->fields[15], 15); vnx::accept(_visitor, output_amounts);
	_visitor.type_field(_type_code->fields[16], 16); vnx::accept(_visitor, contracts);
	_visitor.type_end(*_type_code);
}

void tx_info_t::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.tx_info_t\"";
	_out << ", \"id\": "; vnx::write(_out, id);
	_out << ", \"expires\": "; vnx::write(_out, expires);
	_out << ", \"did_fail\": "; vnx::write(_out, did_fail);
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << ", \"block\": "; vnx::write(_out, block);
	_out << ", \"message\": "; vnx::write(_out, message);
	_out << ", \"fee\": "; vnx::write(_out, fee);
	_out << ", \"cost\": "; vnx::write(_out, cost);
	_out << ", \"note\": "; vnx::write(_out, note);
	_out << ", \"sender\": "; vnx::write(_out, sender);
	_out << ", \"inputs\": "; vnx::write(_out, inputs);
	_out << ", \"outputs\": "; vnx::write(_out, outputs);
	_out << ", \"operations\": "; vnx::write(_out, operations);
	_out << ", \"deployed\": "; vnx::write(_out, deployed);
	_out << ", \"input_amounts\": "; vnx::write(_out, input_amounts);
	_out << ", \"output_amounts\": "; vnx::write(_out, output_amounts);
	_out << ", \"contracts\": "; vnx::write(_out, contracts);
	_out << "}";
}

void tx_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object tx_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.tx_info_t";
	_object["id"] = id;
	_object["expires"] = expires;
	_object["did_fail"] = did_fail;
	_object["height"] = height;
	_object["block"] = block;
	_object["message"] = message;
	_object["fee"] = fee;
	_object["cost"] = cost;
	_object["note"] = note;
	_object["sender"] = sender;
	_object["inputs"] = inputs;
	_object["outputs"] = outputs;
	_object["operations"] = operations;
	_object["deployed"] = deployed;
	_object["input_amounts"] = input_amounts;
	_object["output_amounts"] = output_amounts;
	_object["contracts"] = contracts;
	return _object;
}

void tx_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "block") {
			_entry.second.to(block);
		} else if(_entry.first == "contracts") {
			_entry.second.to(contracts);
		} else if(_entry.first == "cost") {
			_entry.second.to(cost);
		} else if(_entry.first == "deployed") {
			_entry.second.to(deployed);
		} else if(_entry.first == "did_fail") {
			_entry.second.to(did_fail);
		} else if(_entry.first == "expires") {
			_entry.second.to(expires);
		} else if(_entry.first == "fee") {
			_entry.second.to(fee);
		} else if(_entry.first == "height") {
			_entry.second.to(height);
		} else if(_entry.first == "id") {
			_entry.second.to(id);
		} else if(_entry.first == "input_amounts") {
			_entry.second.to(input_amounts);
		} else if(_entry.first == "inputs") {
			_entry.second.to(inputs);
		} else if(_entry.first == "message") {
			_entry.second.to(message);
		} else if(_entry.first == "note") {
			_entry.second.to(note);
		} else if(_entry.first == "operations") {
			_entry.second.to(operations);
		} else if(_entry.first == "output_amounts") {
			_entry.second.to(output_amounts);
		} else if(_entry.first == "outputs") {
			_entry.second.to(outputs);
		} else if(_entry.first == "sender") {
			_entry.second.to(sender);
		}
	}
}

vnx::Variant tx_info_t::get_field(const std::string& _name) const {
	if(_name == "id") {
		return vnx::Variant(id);
	}
	if(_name == "expires") {
		return vnx::Variant(expires);
	}
	if(_name == "did_fail") {
		return vnx::Variant(did_fail);
	}
	if(_name == "height") {
		return vnx::Variant(height);
	}
	if(_name == "block") {
		return vnx::Variant(block);
	}
	if(_name == "message") {
		return vnx::Variant(message);
	}
	if(_name == "fee") {
		return vnx::Variant(fee);
	}
	if(_name == "cost") {
		return vnx::Variant(cost);
	}
	if(_name == "note") {
		return vnx::Variant(note);
	}
	if(_name == "sender") {
		return vnx::Variant(sender);
	}
	if(_name == "inputs") {
		return vnx::Variant(inputs);
	}
	if(_name == "outputs") {
		return vnx::Variant(outputs);
	}
	if(_name == "operations") {
		return vnx::Variant(operations);
	}
	if(_name == "deployed") {
		return vnx::Variant(deployed);
	}
	if(_name == "input_amounts") {
		return vnx::Variant(input_amounts);
	}
	if(_name == "output_amounts") {
		return vnx::Variant(output_amounts);
	}
	if(_name == "contracts") {
		return vnx::Variant(contracts);
	}
	return vnx::Variant();
}

void tx_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "id") {
		_value.to(id);
	} else if(_name == "expires") {
		_value.to(expires);
	} else if(_name == "did_fail") {
		_value.to(did_fail);
	} else if(_name == "height") {
		_value.to(height);
	} else if(_name == "block") {
		_value.to(block);
	} else if(_name == "message") {
		_value.to(message);
	} else if(_name == "fee") {
		_value.to(fee);
	} else if(_name == "cost") {
		_value.to(cost);
	} else if(_name == "note") {
		_value.to(note);
	} else if(_name == "sender") {
		_value.to(sender);
	} else if(_name == "inputs") {
		_value.to(inputs);
	} else if(_name == "outputs") {
		_value.to(outputs);
	} else if(_name == "operations") {
		_value.to(operations);
	} else if(_name == "deployed") {
		_value.to(deployed);
	} else if(_name == "input_amounts") {
		_value.to(input_amounts);
	} else if(_name == "output_amounts") {
		_value.to(output_amounts);
	} else if(_name == "contracts") {
		_value.to(contracts);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const tx_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, tx_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* tx_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> tx_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.tx_info_t";
	type_code->type_hash = vnx::Hash64(0x44e4a710953f4785ull);
	type_code->code_hash = vnx::Hash64(0xfd57fcd9a977150ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::tx_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<tx_info_t>(); };
	type_code->depends.resize(3);
	type_code->depends[0] = ::mmx::tx_note_e::static_get_type_code();
	type_code->depends[1] = ::mmx::txin_t::static_get_type_code();
	type_code->depends[2] = ::mmx::txout_t::static_get_type_code();
	type_code->fields.resize(17);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "id";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "expires";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 1;
		field.name = "did_fail";
		field.code = {31};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "height";
		field.code = {33, 3};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "block";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "message";
		field.code = {33, 32};
	}
	{
		auto& field = type_code->fields[6];
		field.data_size = 8;
		field.name = "fee";
		field.code = {8};
	}
	{
		auto& field = type_code->fields[7];
		field.data_size = 8;
		field.name = "cost";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[8];
		field.is_extended = true;
		field.name = "note";
		field.code = {19, 0};
	}
	{
		auto& field = type_code->fields[9];
		field.is_extended = true;
		field.name = "sender";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[10];
		field.is_extended = true;
		field.name = "inputs";
		field.code = {12, 19, 1};
	}
	{
		auto& field = type_code->fields[11];
		field.is_extended = true;
		field.name = "outputs";
		field.code = {12, 19, 2};
	}
	{
		auto& field = type_code->fields[12];
		field.is_extended = true;
		field.name = "operations";
		field.code = {12, 16};
	}
	{
		auto& field = type_code->fields[13];
		field.is_extended = true;
		field.name = "deployed";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[14];
		field.is_extended = true;
		field.name = "input_amounts";
		field.code = {13, 5, 11, 32, 1, 11, 16, 1};
	}
	{
		auto& field = type_code->fields[15];
		field.is_extended = true;
		field.name = "output_amounts";
		field.code = {13, 5, 11, 32, 1, 11, 16, 1};
	}
	{
		auto& field = type_code->fields[16];
		field.is_extended = true;
		field.name = "contracts";
		field.code = {13, 5, 11, 32, 1, 16};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> tx_info_t::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
	}
	return nullptr;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::tx_info_t& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.expires, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.did_fail, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[6]) {
			vnx::read_value(_buf + _field->offset, value.fee, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[7]) {
			vnx::read_value(_buf + _field->offset, value.cost, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.id, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.height, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.block, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.message, type_code, _field->code.data()); break;
			case 8: vnx::read(in, value.note, type_code, _field->code.data()); break;
			case 9: vnx::read(in, value.sender, type_code, _field->code.data()); break;
			case 10: vnx::read(in, value.inputs, type_code, _field->code.data()); break;
			case 11: vnx::read(in, value.outputs, type_code, _field->code.data()); break;
			case 12: vnx::read(in, value.operations, type_code, _field->code.data()); break;
			case 13: vnx::read(in, value.deployed, type_code, _field->code.data()); break;
			case 14: vnx::read(in, value.input_amounts, type_code, _field->code.data()); break;
			case 15: vnx::read(in, value.output_amounts, type_code, _field->code.data()); break;
			case 16: vnx::read(in, value.contracts, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::tx_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_tx_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::tx_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(21);
	vnx::write_value(_buf + 0, value.expires);
	vnx::write_value(_buf + 4, value.did_fail);
	vnx::write_value(_buf + 5, value.fee);
	vnx::write_value(_buf + 13, value.cost);
	vnx::write(out, value.id, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.height, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.block, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.message, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.note, type_code, type_code->fields[8].code.data());
	vnx::write(out, value.sender, type_code, type_code->fields[9].code.data());
	vnx::write(out, value.inputs, type_code, type_code->fields[10].code.data());
	vnx::write(out, value.outputs, type_code, type_code->fields[11].code.data());
	vnx::write(out, value.operations, type_code, type_code->fields[12].code.data());
	vnx::write(out, value.deployed, type_code, type_code->fields[13].code.data());
	vnx::write(out, value.input_amounts, type_code, type_code->fields[14].code.data());
	vnx::write(out, value.output_amounts, type_code, type_code->fields[15].code.data());
	vnx::write(out, value.contracts, type_code, type_code->fields[16].code.data());
}

void read(std::istream& in, ::mmx::tx_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::tx_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::tx_info_t& value) {
	value.accept(visitor);
}

} // vnx
