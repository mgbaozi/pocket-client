#include "config.h"
#include <boost/property_tree/json_parser.hpp>
#include <fstream>
#include <sstream>

using namespace pocket;
using namespace pocket::model;
using namespace boost::property_tree;

std::string Config::config_file_;

Config::Config()
{
	init();
}

Config::~Config()
{
	std::ofstream fs(config_file_);
	std::stringstream ss;
	write_json(ss, config_);
	fs << ss.str();
}

void Config::init()
{
	if(!config_.empty())
	{
		ptree empty_tree;
		config_.swap(empty_tree);
	}
	if(config_file_.empty())
	{
		config_file_ = "config.json";
	}
	std::ifstream fs(config_file_);
	std::stringstream ss;
	ss << fs.rdbuf();
	read_json(ss, config_);
}

ptree& Config::get_config(const std::string& key)
{
	return config_.get_child(key);
}

void Config::set_config(const std::string& key, const ptree& value)
{
	config_.put_child(key, value);
}
