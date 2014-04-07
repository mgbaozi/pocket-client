#ifndef POCKET_MODEL_RESOURCE_H
#define POCKET_MODEL_RESOURCE_H
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include "../base/singleton.h"
#include "../base/types.h"
#include <string>
#include <map>

namespace pocket
{

namespace model
{
class ResourceData;
class Resource : boost::noncopyable
{
public:
	static Resource& instance()
	{
		return Singleton<Resource>::instance();
	}
private:
	Resource();
	~Resource();

private:
	bool load_image(uint32_t id, const std::string& filename);
	bool load_sound(uint32_t id, const std::string& filename);
	bool load_animation(uint32_t id, const std::string& filename);

public:
	ImagePtr get_image(uint32_t id);

private:
	boost::scoped_ptr<ResourceData> res_data_;

private:
	typedef std::map<uint32_t, ImagePtr> ImageMap;
	ImageMap images_;


friend class Singleton<Resource>;
};

} //namespace model

} //namespace pocket
#endif
