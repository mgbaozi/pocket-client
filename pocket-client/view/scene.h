#ifndef POCKET_VIEW_SCENE_H
#define POCKET_VIEW_SCENE_H
#include <boost/noncopyable.hpp>
#include "ObjectTypes.h"
namespace pocket
{

namespace view
{
class Scene : boost::noncopyable
{
public:
	Scene();
	~Scene();

private:
	void init();

public:
	inline ObjectList& get_object_list()
	{
		return object_list_;
	}

private:
	ObjectList object_list_;
}

} //namespace view

} //namespace pocket
#endif
