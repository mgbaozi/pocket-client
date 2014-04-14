#include "GraphicsAdapter.h"
#include "ViewObject.h"

using namespace pocket;
using namespace view;

GraphicsAdapter::GraphicsAdapter()
{

}

GraphicsAdapter::~GraphicsAdapter()
{

}

void GraphicsAdapter::display(ObjectList& objects)
{
	clear();
	for(auto iter = objects.rbegin(); iter != objects.rend(); ++iter)
	{
		display_object(*iter);
	}
	swap_buffer_();
}	
