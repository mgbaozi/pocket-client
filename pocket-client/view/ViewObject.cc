#include "viewobject.h"
#include <math.h>

using namespace pocket;
using namespace view;

ViewObject::ViewObject()
{
}

ViewObject::~ViewObject()
{

}

std::vector<ImageObject>& get_display_list()
{
	return display_list_;
}

void ViewObject::move_x(float x, time_t time = 0)
{
	state_.pos_x += x;
}

void ViewObject::move_y(float y, time_t time = 0)
{
	state_.pos_y += y;
}

void ViewObject::rotate(float angle, time_t time = 0)
{
	state_.angle += angle;
	while(state_.angle > M_PI * 2)
	{
		state_.angle -= M_PI * 2;
	}
}
