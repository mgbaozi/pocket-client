#include "QtGLWindow.h"
#include "view/OpenGLAdapter.h"
#include "view/scene.h"
#include <functional>

using namespace pocket;
using namespace view;

//TODO:change scene to director
QtGLWindow::QGLWindow(QWidget *parents)
	:QGLWidget(parents),
	graphic_(OpenGLAdapter::instance()),
	paint_timer_(new QTimer),
	scene_(new Scene)
{
	connect(paint_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
}

QtGLWindow::~QGLWindow()
{

}

void QtGLWindow::initializeGL()
{
	graphic_.init();
	setAutoBufferSwap(false);
	graphic_.set_swap_buffer_func(std::bind(&QWidget::swapBuffers, this));
	paint_timer -> start(1000.0f/60.0f);
}

void QtGLWindow::resizeGL(int width, int height)
{
	graphic_.resize(width, height);
}

void QtGLWindow::paintGL()
{
	graphic_.display(scene_-> get_objects());
}
