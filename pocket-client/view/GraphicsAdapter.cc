#include "GraphicsAdapter.h"

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
	for(auto iter = objects.begin(); iter != iter.end(); ++iter)
	{
		display_object(*iter);
	}
	swap_buffer_();
}	
