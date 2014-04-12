#include "OpenGLAdapter.h"
#include "ViewObject.h"
#include "ObjectState.h"
#include <math.h>
using namespace pocket;
using namespace view;

static inline float gl_x(float x)
{
	return x*2 - 1.0f;
}
static inline float gl_y(float y)
{
	return 1.0f - y*2;
}
static inline float gl_width(float width)
{
	return width * 2;
}
static inline float gl_height(float height)
{
	return -height * 2
}
OpenGLAdapter::OpenGLAdapter()
	:GraphicsAdapter()
{
	set_swap_buffer_func(std::bind(&glFlush));
}

OpenGLAdapter::~OpenGLAdapter()
{

}

void OpenGLAdapter::init()
{
	glClearColor(0.0f, 0.0f,0.0f,0.0f);
	glShadeModel(GL_FLAT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLAdapter::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}
void OpenGLAdapter::display_object(ViewObject& object)
{
	auto& display_list = object.get_display_list();
	for(auto iter = display_list.begin(); iter != display_list.end(); ++iter)
	{
		if(iter -> id == 0)
		{
			bind_texture(*iter);
		}
		const auto& state = object.get_state();
		paint_image(state.pos_x + iter->pos_x, state.pos_y + iter->pos_y, iter->width, iter->height, state.angle,
					state.pos_x + state.width/2, state.pos_y + state.height/2, iter->id);

	}

}

void OpenGLAdapter::resize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void OpenGLAdapter::bind_texture(ImageObject& object)
{
	glGenTextures(1, &object.id);
	glBindTexture(GL_TEXTURE_2D, object.id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	auto& image = objcet.image;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width,
									image->height, 0, GL_RGBA,
									GL_UNSIGNED_BYTE, &image->data[0]);
}

void OpenGLAdapter::paint_image(float x, float y, float width, float height, float angle, float c_x, float c_y, uint32_t id)
{
	float x1 = x - c_x, y1 = y - c_y;
	float x2 = x - c_x, y2 = y + height - c_y;
	float x3 = x + width - c_x, y3 = y + height - c_y;
	float x4 = x + width - c_x, y4 = y - c_y;
	float sin_angle = ::sin(angle);
	float cos_angle = ::cos(angle);
	glBindTexture(GL_TEXTURE_2D, id);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f,0.0f);glVertex3f(c_x+x1*cos_angle-y1*sin_angle, c_y+x1*sin_angle+y1*cos_angle, 0.0f);
		glTexCoord2f(0.0f,1.0f);glVertex3f(c_x+x2*cos_angle-y2*sin_angle, c_y+x2*sin_angle+y2*cos_angle, 0.0f);
		glTexCoord2f(1.0f,1.0f);glVertex3f(c_x+x3*cos_angle-y3*sin_angle, c_y+x3*sin_angle+y3*cos_angle, 0.0f);
		glTexCoord2f(1.0f,0.0f);glVertex3f(c_x+x4*cos_angle-y4*sin_angle, c_y+x4*sin_angle+y4*cos_angle, 0.0f);
	glEnd();

}
