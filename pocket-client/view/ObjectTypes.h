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
	float pos_x, pos_y;
	float width, height;
};
struct ObjectState : public Rect
{
	float angle;
};

struct ImageObject : public Rect
{
	ImageObject()
		:Rect(), id(0)
	{
	}
	ImagePtr image;
	uint32_t id;
}
class ViewObject;
typedef boost::ptr_vector<ViewObject> ObjectList;

} //namespace view

} //namespace pocket
#endif
