
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_contract_PuzzleLock_HXX_
#define INCLUDE_mmx_contract_PuzzleLock_HXX_

#include <mmx/contract/package.hxx>
#include <mmx/Contract.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/contract/Locked.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/pubkey_t.hpp>


namespace mmx {
namespace contract {

class MMX_CONTRACT_EXPORT PuzzleLock : public ::mmx::contract::Locked {
public:
	
	std::shared_ptr<const ::mmx::Contract> puzzle;
	::mmx::addr_t target;
	
	typedef ::mmx::contract::Locked Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xf33097b29a62c755ull;
	
	PuzzleLock() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<PuzzleLock> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const PuzzleLock& _value);
	friend std::istream& operator>>(std::istream& _in, PuzzleLock& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void PuzzleLock::accept_generic(T& _visitor) const {
	_visitor.template type_begin<PuzzleLock>(6);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("owner", 1); _visitor.accept(owner);
	_visitor.type_field("chain_height", 2); _visitor.accept(chain_height);
	_visitor.type_field("delta_height", 3); _visitor.accept(delta_height);
	_visitor.type_field("puzzle", 4); _visitor.accept(puzzle);
	_visitor.type_field("target", 5); _visitor.accept(target);
	_visitor.template type_end<PuzzleLock>(6);
}


} // namespace mmx
} // namespace contract


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_contract_PuzzleLock_HXX_
