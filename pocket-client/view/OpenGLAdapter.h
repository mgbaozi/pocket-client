#ifndef POCKET_VIEW_OPENGL_ADAPTER_H
#define POCKET_VIEW_OPENGL_ADAPTER_H
#include "GraphicsAdapter.h"
#include "../base/singleton.h"

namespace pocket
{

namespace view
{

class ViewObject;
struct ImageObject;
class OpenGLAdapter : public GraphicsAdapter
{
public:
	static OpenGLAdapter& instance()
	{
		return Singleton<OpenGLAdapter>::instance();
	}

public:
	virtual void clear();
	virtual void display_object(ViewObject& object);
	virtual void resize(int width, int height);

private:
	OpenGLAdapter();
	virtual ~OpenGLAdapter();
private:
	virtual void init();
	void bind_texture(ImageObject& object);

private:
	void paint_image(float x, float y, float width, float height, float angle, float c_x, float c_y,  uint32_t id);

friend class Singleton<OpenGLAdapter>;

};

} // namespace view
} // namespace pocket

#endif
