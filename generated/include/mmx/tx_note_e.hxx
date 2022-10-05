
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_tx_note_e_HXX_
#define INCLUDE_mmx_tx_note_e_HXX_

#include <vnx/Type.h>
#include <mmx/package.hxx>


namespace mmx {

struct MMX_EXPORT tx_note_e {
	
	enum enum_t : uint32_t {
		BURN = 1273454750l,
		CLAIM = 3251493825l,
		DEPLOY = 251696509l,
		DEPOSIT = 4272391094l,
		EXECUTE = 356250251l,
		MINT = 2140500429l,
		MUTATE = 2579166487l,
		OFFER = 1549148948l,
		REVOKE = 3821531424l,
		REWARD = 3842121424l,
		TIMELORD_REWARD = 1783340485l,
		TRADE = 329618288l,
		TRANSFER = 858544509l,
		WITHDRAW = 4266232802l,
	};
	
	::mmx::tx_note_e::enum_t value = ::mmx::tx_note_e::enum_t(0);
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x347c1deca0a9c9cull;
	
	tx_note_e() {}
	
	tx_note_e(const enum_t& _value) { value = _value; }
	tx_note_e(const ::mmx::tx_note_e& _other) { value = _other.value; }
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	operator enum_t() const { return value; }
	tx_note_e& operator=(const enum_t& _value) { value = _value; return *this; }
	tx_note_e& operator=(const ::mmx::tx_note_e& _other) { value = _other.value; return *this; }
	
	static std::shared_ptr<tx_note_e> create();
	std::shared_ptr<tx_note_e> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::bool_t is_valid() const;
	std::string to_string() const;
	std::string to_string_value() const;
	std::string to_string_value_full() const;
	
	void from_string(const std::string& str);
	void from_string_value(const std::string& name);
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const tx_note_e& _value);
	friend std::istream& operator>>(std::istream& _in, tx_note_e& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void tx_note_e::accept_generic(T& _visitor) const {
	_visitor.template type_begin<tx_note_e>(1);
	_visitor.type_field("value", 0); _visitor.accept(value);
	_visitor.template type_end<tx_note_e>(1);
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::tx_note_e::enum_t& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void write(TypeOutput& out, const ::mmx::tx_note_e::enum_t& value, const TypeCode* type_code, const uint16_t* code); ///< \private

template<>
std::string to_string(const ::mmx::tx_note_e& _value); ///< \private

template<>
std::string to_string_value(const ::mmx::tx_note_e& _value); ///< \private

template<>
std::string to_string_value_full(const ::mmx::tx_note_e& _value); ///< \private

template<>
std::string to_string(const ::mmx::tx_note_e::enum_t& _value); ///< \private

template<>
std::string to_string_value(const ::mmx::tx_note_e::enum_t& _value); ///< \private

template<>
std::string to_string_value_full(const ::mmx::tx_note_e::enum_t& _value); ///< \private

template<>
struct is_equivalent<::mmx::tx_note_e> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_tx_note_e_HXX_
