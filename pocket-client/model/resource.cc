#include "resource.h"
#include "resdata.h"
#include <lodepng.h>
#include <sstream>
#include <fstream>
#include <assert.h>

using namespace pocket;
using namespace pocket::model;

Resource::Resource()
	:res_data_(new ResourceData)
{
}

Resource::~Resource()
{
}

bool Resource::load_image(uint32_t id, const std::string& filename)
{
	ImagePtr image(new Image);
	unsigned int error = lodepng::decode(image->data, image->width, image->height, filename);	
	if(error)
	{
		return false;
	}
	images_.insert(ImageMap::value_type(id, image));
	return true;
}

bool Resource::load_sound(uint32_t id, const std::string& filename)
{

	return true;
}

bool Resource::load_animation(uint32_t id, const std::string& filename)
{

	return true;
}

ImagePtr Resource::get_image(uint32_t id)
{
	ImageMap::iterator iter = images_.find(id);
	if(iter != images_.end())
	{
		ImagePtr image = iter -> second;
		if(image.get() != nullptr)
		{
			return image;
		}
	}
	if(load_image(id, res_data_ -> get_image_path(id)))
	{
		return images_[id];
	}
	return ImagePtr(nullptr);
}

