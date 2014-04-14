#include "QtGLWindow.h"
#include "view/OpenGLAdapter.h"
#include "view/scene.h"
#include <functional>

using namespace pocket;
using namespace view;

//TODO:change scene to director
QtGLWindow::QtGLWindow(QWidget *parents)
	:QGLWidget(parents),
	scene_(new Scene),
	graphic_(OpenGLAdapter::instance()),
	paint_timer_(new QTimer)
{
	connect(paint_timer_.get(), SIGNAL(timeout()), this, SLOT(updateGL()));
}

QtGLWindow::~QtGLWindow()
{

}

void QtGLWindow::initializeGL()
{
	graphic_.init();
	setAutoBufferSwap(false);
	graphic_.set_swap_buffer_func(std::bind(&QGLWidget::swapBuffers, this));
	paint_timer_ -> start(1000.0f/60.0f);
}

void QtGLWindow::resizeGL(int width, int height)
{
	graphic_.resize(width, height);
}

void QtGLWindow::paintGL()
{
	graphic_.display(scene_-> get_object_list());
}

