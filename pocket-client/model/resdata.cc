#include "resdata.h"
#include "config.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
using namespace boost::property_tree;
using namespace pocket;
using namespace model;
const std::string ResourceData::list_file_name = "resource.json";
ResourceData::ResourceData()
{
	Config& config = Config::instance();
	const auto& res_config = config.get_config("resource");
	resource_path_ = res_config.get<std::string>("path");
	load_resource_maps();
}
ResourceData::~ResourceData()
{

}
void ResourceData::load_resource_map(ptree& res_tree, ResourceMap &res_map)
{
	BOOST_FOREACH(const ptree::value_type &v, res_tree)
	{
		assert(v.first.empty());
		const ptree& item = v.second;
		uint32_t id = item.get<uint32_t>("id");
		std::string file_path = resource_path_ + "/" + item.get<std::string>("path") + "/" + item.get<std::string>("filename");
		res_map.insert(ResourceMap::value_type(id, file_path));
	}
}
void ResourceData::load_resource_maps()
{
	std::string list_file = resource_path_ + "/" + list_file_name;
	std::ifstream fs(list_file);
	std::stringstream ss;
	ss << fs.rdbuf();
	boost::property_tree::ptree resource_tree;
	read_json(ss, resource_tree);
	load_resource_map(resource_tree.get_child("image"), image_res_);
	load_resource_map(resource_tree.get_child("sound"), sound_res_);
	load_resource_map(resource_tree.get_child("animation"), animation_res_);
}

const std::string& ResourceData::get_image_path(uint32_t id)
{
	return image_res_[id];
}
