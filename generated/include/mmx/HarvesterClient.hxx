
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Harvester_CLIENT_HXX_
#define INCLUDE_mmx_Harvester_CLIENT_HXX_

#include <vnx/Client.h>
#include <mmx/Challenge.hxx>
#include <mmx/FarmInfo.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>


namespace mmx {

class HarvesterClient : public vnx::Client {
public:
	HarvesterClient(const std::string& service_name);
	
	HarvesterClient(vnx::Hash64 service_addr);
	
	void reload();
	
	void reload_async();
	
	void add_plot_dir(const std::string& path = "");
	
	void add_plot_dir_async(const std::string& path = "");
	
	void rem_plot_dir(const std::string& path = "");
	
	void rem_plot_dir_async(const std::string& path = "");
	
	std::shared_ptr<const ::mmx::FarmInfo> get_farm_info();
	
	uint64_t get_total_bytes();
	
	std::shared_ptr<const ::vnx::addons::HttpResponse> http_request(std::shared_ptr<const ::vnx::addons::HttpRequest> request = nullptr, const std::string& sub_path = "");
	
	std::shared_ptr<const ::vnx::addons::HttpData> http_request_chunk(std::shared_ptr<const ::vnx::addons::HttpRequest> request = nullptr, const std::string& sub_path = "", const int64_t& offset = 0, const int64_t& max_bytes = 0);
	
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
	
};


} // namespace mmx

#endif // INCLUDE_mmx_Harvester_CLIENT_HXX_
