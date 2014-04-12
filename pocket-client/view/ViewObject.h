#ifndef POCKET_VIEW_VIEWOBJECT_H
#define POCKET_VIEW_VIEWOBJECT_H
#include <vector>
#include <time.h>
#include "ObjectTypes.h"
namespace pocket
{

namespace view
{

class ViewObject
{
public:
	ViewObject();
	virtual ~ViewObject();

public: //getter
	std::vector<ImageObject>& get_display_list();

public:
	const ObjectState& get_state()
	{
		return state_;
	}
	void move_x(float x, time_t time = 0);
	void move_y(float y, time_t time = 0);
	void rotate(float angle, time_t time =0);

protected:
	std::vector<ImageObject> display_list_;
	ObjectState state_;
};

} //namespace view

} //namespace pocket
#endif
