
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/IntervalRequest.hxx>
#include <mmx/hash_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 IntervalRequest::VNX_TYPE_HASH(0xa4e39be061f13d71ull);
const vnx::Hash64 IntervalRequest::VNX_CODE_HASH(0x5c686ffc7142f175ull);

vnx::Hash64 IntervalRequest::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string IntervalRequest::get_type_name() const {
	return "mmx.IntervalRequest";
}

const vnx::TypeCode* IntervalRequest::get_type_code() const {
	return mmx::vnx_native_type_code_IntervalRequest;
}

std::shared_ptr<IntervalRequest> IntervalRequest::create() {
	return std::make_shared<IntervalRequest>();
}

std::shared_ptr<vnx::Value> IntervalRequest::clone() const {
	return std::make_shared<IntervalRequest>(*this);
}

void IntervalRequest::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void IntervalRequest::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void IntervalRequest::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_IntervalRequest;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, begin);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, end);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, start_values);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, has_start);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, num_segments);
	_visitor.type_end(*_type_code);
}

void IntervalRequest::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.IntervalRequest\"";
	_out << ", \"begin\": "; vnx::write(_out, begin);
	_out << ", \"end\": "; vnx::write(_out, end);
	_out << ", \"start_values\": "; vnx::write(_out, start_values);
	_out << ", \"has_start\": "; vnx::write(_out, has_start);
	_out << ", \"num_segments\": "; vnx::write(_out, num_segments);
	_out << "}";
}

void IntervalRequest::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object IntervalRequest::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.IntervalRequest";
	_object["begin"] = begin;
	_object["end"] = end;
	_object["start_values"] = start_values;
	_object["has_start"] = has_start;
	_object["num_segments"] = num_segments;
	return _object;
}

void IntervalRequest::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "begin") {
			_entry.second.to(begin);
		} else if(_entry.first == "end") {
			_entry.second.to(end);
		} else if(_entry.first == "has_start") {
			_entry.second.to(has_start);
		} else if(_entry.first == "num_segments") {
			_entry.second.to(num_segments);
		} else if(_entry.first == "start_values") {
			_entry.second.to(start_values);
		}
	}
}

vnx::Variant IntervalRequest::get_field(const std::string& _name) const {
	if(_name == "begin") {
		return vnx::Variant(begin);
	}
	if(_name == "end") {
		return vnx::Variant(end);
	}
	if(_name == "start_values") {
		return vnx::Variant(start_values);
	}
	if(_name == "has_start") {
		return vnx::Variant(has_start);
	}
	if(_name == "num_segments") {
		return vnx::Variant(num_segments);
	}
	return vnx::Variant();
}

void IntervalRequest::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "begin") {
		_value.to(begin);
	} else if(_name == "end") {
		_value.to(end);
	} else if(_name == "start_values") {
		_value.to(start_values);
	} else if(_name == "has_start") {
		_value.to(has_start);
	} else if(_name == "num_segments") {
		_value.to(num_segments);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const IntervalRequest& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, IntervalRequest& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* IntervalRequest::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> IntervalRequest::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.IntervalRequest";
	type_code->type_hash = vnx::Hash64(0xa4e39be061f13d71ull);
	type_code->code_hash = vnx::Hash64(0x5c686ffc7142f175ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::IntervalRequest);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<IntervalRequest>(); };
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.data_size = 8;
		field.name = "begin";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 8;
		field.name = "end";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "start_values";
		field.code = {11, 2, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 1;
		field.name = "has_start";
		field.code = {31};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 4;
		field.name = "num_segments";
		field.code = {3};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::IntervalRequest& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.begin, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.end, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.has_start, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.num_segments, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 2: vnx::read(in, value.start_values, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::IntervalRequest& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_IntervalRequest;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::IntervalRequest>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(21);
	vnx::write_value(_buf + 0, value.begin);
	vnx::write_value(_buf + 8, value.end);
	vnx::write_value(_buf + 16, value.has_start);
	vnx::write_value(_buf + 17, value.num_segments);
	vnx::write(out, value.start_values, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::IntervalRequest& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::IntervalRequest& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::IntervalRequest& value) {
	value.accept(visitor);
}

} // vnx
