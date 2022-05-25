
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_WalletBase_HXX_
#define INCLUDE_mmx_WalletBase_HXX_

#include <mmx/package.hxx>
#include <mmx/Contract.hxx>
#include <mmx/FarmerKeys.hxx>
#include <mmx/Solution.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/account_t.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/address_info_t.hxx>
#include <mmx/balance_t.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/spend_options_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/tx_log_entry_t.hxx>
#include <mmx/txin_t.hxx>
#include <mmx/uint128.hpp>
#include <vnx/Module.h>
#include <vnx/Object.hpp>
#include <vnx/Variant.hpp>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>


namespace mmx {

class MMX_EXPORT WalletBase : public ::vnx::Module {
public:
	
	std::vector<std::string> key_files;
	std::vector<::mmx::account_t> accounts;
	std::string config_path;
	std::string storage_path;
	std::string database_path = "wallet/";
	std::string node_server = "Node";
	uint32_t max_key_files = 100;
	uint32_t num_addresses = 100;
	int32_t cache_timeout_ms = 1000;
	vnx::bool_t enable_bls = true;
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x62207fd96d3aead7ull;
	
	WalletBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const WalletBase& _value);
	friend std::istream& operator>>(std::istream& _in, WalletBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual std::shared_ptr<const ::mmx::Transaction> send(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> send_many(const uint32_t& index, const std::map<::mmx::addr_t, uint64_t>& amounts, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> send_from(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& src_addr, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> mint(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> deploy(const uint32_t& index, std::shared_ptr<const ::mmx::Contract> contract, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> mutate(const uint32_t& index, const ::mmx::addr_t& address, const ::vnx::Object& method, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> execute(const uint32_t& index, const ::mmx::addr_t& address, const std::string& method, const std::vector<::vnx::Variant>& args, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> deposit(const uint32_t& index, const ::mmx::addr_t& address, const std::string& method, const std::vector<::vnx::Variant>& args, const uint64_t& amount, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> make_offer(const uint32_t& index, const uint32_t& address, const uint64_t& bid_amount, const ::mmx::addr_t& bid_currency, const uint64_t& ask_amount, const ::mmx::addr_t& ask_currency, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> accept_offer(const uint32_t& index, std::shared_ptr<const ::mmx::Transaction> offer, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> revoke(const uint32_t& index, const ::mmx::hash_t& txid, const ::mmx::addr_t& address, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> complete(const uint32_t& index, std::shared_ptr<const ::mmx::Transaction> tx, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> sign_off(const uint32_t& index, std::shared_ptr<const ::mmx::Transaction> tx, const vnx::bool_t& cover_fee, const ::mmx::spend_options_t& options) const = 0;
	virtual std::shared_ptr<const ::mmx::Solution> sign_msg(const uint32_t& index, const ::mmx::addr_t& address, const ::mmx::hash_t& msg) const = 0;
	virtual void send_off(const uint32_t& index, std::shared_ptr<const ::mmx::Transaction> tx) const = 0;
	virtual void mark_spent(const uint32_t& index, const std::map<std::pair<::mmx::addr_t, ::mmx::addr_t>, ::mmx::uint128>& amounts) = 0;
	virtual void reserve(const uint32_t& index, const std::map<std::pair<::mmx::addr_t, ::mmx::addr_t>, ::mmx::uint128>& amounts) = 0;
	virtual void release(const uint32_t& index, const std::map<std::pair<::mmx::addr_t, ::mmx::addr_t>, ::mmx::uint128>& amounts) = 0;
	virtual void release_all() = 0;
	virtual void reset_cache(const uint32_t& index) = 0;
	virtual void update_cache(const uint32_t& index) const = 0;
	virtual std::vector<::mmx::tx_entry_t> get_history(const uint32_t& index, const int32_t& since) const = 0;
	virtual std::vector<::mmx::tx_log_entry_t> get_tx_history(const uint32_t& index, const int32_t& limit, const uint32_t& offset) const = 0;
	virtual std::vector<::mmx::txin_t> gather_inputs_for(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) const = 0;
	virtual ::mmx::balance_t get_balance(const uint32_t& index, const ::mmx::addr_t& currency, const uint32_t& min_confirm) const = 0;
	virtual std::map<::mmx::addr_t, ::mmx::balance_t> get_balances(const uint32_t& index, const uint32_t& min_confirm) const = 0;
	virtual std::map<::mmx::addr_t, std::shared_ptr<const ::mmx::Contract>> get_contracts(const uint32_t& index) const = 0;
	virtual ::mmx::addr_t get_address(const uint32_t& index, const uint32_t& offset) const = 0;
	virtual std::vector<::mmx::addr_t> get_all_addresses(const int32_t& index) const = 0;
	virtual ::mmx::address_info_t get_address_info(const uint32_t& index, const uint32_t& offset) const = 0;
	virtual std::vector<::mmx::address_info_t> get_all_address_infos(const int32_t& index) const = 0;
	virtual ::mmx::account_t get_account(const uint32_t& index) const = 0;
	virtual std::map<uint32_t, ::mmx::account_t> get_all_accounts() const = 0;
	virtual void add_account(const uint32_t& index, const ::mmx::account_t& config) = 0;
	virtual void create_account(const ::mmx::account_t& config) = 0;
	virtual void create_wallet(const ::mmx::account_t& config, const vnx::optional<::mmx::hash_t>& seed) = 0;
	virtual ::mmx::hash_t get_master_seed(const uint32_t& index) const = 0;
	virtual std::shared_ptr<const ::mmx::FarmerKeys> get_farmer_keys(const uint32_t& index) const = 0;
	virtual std::vector<std::shared_ptr<const ::mmx::FarmerKeys>> get_all_farmer_keys() const = 0;
	virtual void http_request_async(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const vnx::request_id_t& _request_id) const = 0;
	void http_request_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpResponse>& _ret_0) const;
	virtual void http_request_chunk_async(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const int64_t& offset, const int64_t& max_bytes, const vnx::request_id_t& _request_id) const = 0;
	void http_request_chunk_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpData>& _ret_0) const;
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};

template<typename T>
void WalletBase::accept_generic(T& _visitor) const {
	_visitor.template type_begin<WalletBase>(10);
	_visitor.type_field("key_files", 0); _visitor.accept(key_files);
	_visitor.type_field("accounts", 1); _visitor.accept(accounts);
	_visitor.type_field("config_path", 2); _visitor.accept(config_path);
	_visitor.type_field("storage_path", 3); _visitor.accept(storage_path);
	_visitor.type_field("database_path", 4); _visitor.accept(database_path);
	_visitor.type_field("node_server", 5); _visitor.accept(node_server);
	_visitor.type_field("max_key_files", 6); _visitor.accept(max_key_files);
	_visitor.type_field("num_addresses", 7); _visitor.accept(num_addresses);
	_visitor.type_field("cache_timeout_ms", 8); _visitor.accept(cache_timeout_ms);
	_visitor.type_field("enable_bls", 9); _visitor.accept(enable_bls);
	_visitor.template type_end<WalletBase>(10);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_WalletBase_HXX_
