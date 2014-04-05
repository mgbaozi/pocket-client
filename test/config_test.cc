#include "config.h"
#include <assert.h>
#include <string>
using namespace pocket;
using namespace model;
int main()
{
	Config::set_config_file("config.json");
	Config& config = Config::instance();
	auto server_conf = config.get_config("server");
	assert(server_conf.get<std::string>("address") == "127.0.0.1");
	assert(server_conf.get<int>("port") == 41107);
	return 0;
}
