#include "resource.h"
#include "config.h"

using namespace pocket;
using namespace pocket::model;

Resource::Resource()
{
	Config& config = Config::instance();
	const auto& res_config = config.get_config("resource");
	resource_path_ = res_config.get<string>("path");
}

Resource::~Resource()
{
}
