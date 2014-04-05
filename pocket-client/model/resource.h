#ifndef POCKET_MODEL_RESOURCE_H
#define POCKET_MODEL_RESOURCE_H
#include <boost/noncopyable.hpp>
#include "../base/singleton.h"
#include <string>

namespace pocket
{

namespace model
{
class Resource : boost::noncopyable
{
public:
	static Resource& instance()
	{
		return base::Singleton<Resource>::instance();
	}
private:
	Resource();
	~Resource();
	std::string resource_path_;

friend class base::Singleton<Resource>;
};

} //namespace model

} //namespace pocket
#endif
