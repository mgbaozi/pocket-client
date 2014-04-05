#ifndef POCKET_MODEL_CONFIG_H
#define POCKET_MODEL_CONFIG_H
#include <boost/noncopyable.hpp>
#include "../base/singleton.h"
#include <boost/property_tree/ptree.hpp>
#include <string>

namespace pocket
{

namespace model
{

class Config : boost::noncopyable
{
public:
	static Config& instance()
	{
		return base::Singleton<Config>::instance();
	}
	inline void reload()
	{
		init();
	}
	boost::property_tree::ptree& get_config(const std::string& key);
	void set_config(const std::string& key, const boost::property_tree::ptree& value);
	static void set_config_file(const std::string& file)
	{
		config_file_ = file;
	}
private:
	Config();
	~Config();
	void init();
	boost::property_tree::ptree config_;
	static std::string config_file_;

friend class base::Singleton<Config>;
};

} //namespace model
} //namespace pocket

#endif
