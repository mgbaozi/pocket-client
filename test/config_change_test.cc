#include "config.h"
#include <assert.h>
#include <string>
using namespace pocket;
using namespace model;
int main()
{
	Config::set_config_file("config.json");
	Config& config = Config::instance();
	auto& resource_conf = config.get_config("resource");
	resource_conf.put<std::string>("path", "test");
	assert(resource_conf.get<std::string>("path")=="test");
	//config.set_config("resource", resource_conf);
	resource_conf = config.get_config("resource");
	assert(resource_conf.get<std::string>("path")=="test");
	return 0;
}
