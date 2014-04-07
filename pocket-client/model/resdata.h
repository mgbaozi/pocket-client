#ifndef POCKET_MODEL_RESDATA_H
#define POCKET_MODEL_RESDATA_H
#include <boost/property_tree/ptree.hpp>
#include <map>
#include <string>
namespace pocket
{

namespace model
{

class ResourceData
{
public:
	ResourceData();
	~ResourceData();
	const std::string& get_image_path(uint32_t id);
private:
	typedef std::map<uint32_t, std::string> ResourceMap;
	ResourceMap image_res_, sound_res_, animation_res_;

private:
	void load_resource_map(boost::property_tree::ptree& res_tree, ResourceMap &res_map);
	void load_resource_maps();

private:
	std::string resource_path_;
	static const std::string list_file_name;
};

} //namespace model

} //namespace pocket
#endif
