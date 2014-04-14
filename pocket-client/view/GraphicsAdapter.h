#ifndef POCKET_VIEW_GRAPHICS_ADAPTER_H
#define POCKET_VIEW_GRAPHICS_ADAPTER_H
#include <boost/noncopyable.hpp>
#include "../base/types.h"
#include "ObjectTypes.h"
namespace pocket
{

namespace view
{

class GraphicsAdapter : boost::noncopyable
{
public:
	GraphicsAdapter();
	virtual ~GraphicsAdapter();
	void display(ObjectList& objects);
	virtual void clear() = 0;
	virtual void display_object(ViewObject& object) = 0;
	virtual void resize(int width, int height) = 0;
	inline void set_swap_buffer_func(VoidFunction swap_buffer)
	{
		swap_buffer_ = swap_buffer;
	}
	virtual void init() = 0;
private:
	VoidFunction swap_buffer_;
};

} // namespace view

} // namespace pocket
#endif
