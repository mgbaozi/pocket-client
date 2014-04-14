#ifndef POCKET_VIEW_OBJECT_TYPES_H
#define POCKET_VIEW_OBJECT_TYPES_H
#include <boost/ptr_container/ptr_vector.hpp>
#include "../base/types.h"
#include <memory>
namespace pocket
{

namespace view
{

struct Rect
{
	Rect()
	{
	}
	Rect(float x, float y, float width, float height)
		:pos_x(x), pos_y(y), width(width), height(height)
	{
	}
	float pos_x, pos_y;
	float width, height;
};
struct ObjectState : public Rect
{
	ObjectState()
		:Rect()
	{
	}
	ObjectState(float x, float y, float width, float height, float angle)
		:Rect(x, y, width, height), angle(angle)
	{
	}
	float angle;
};

struct ImageObject : public Rect
{
	ImageObject()
		:Rect(), id(0)
	{
	}
	ImageObject(float x, float y, float width, float height, ImagePtr image, uint32_t id)
		:Rect(x, y, width, height), image(image), id(id)
	{
	}
	ImagePtr image;
	uint32_t id;
};
class ViewObject;
typedef boost::ptr_vector<ViewObject> ObjectList;

} //namespace view

} //namespace pocket
#endif
