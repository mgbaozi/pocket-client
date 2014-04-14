#ifndef POCKET_QTGL_WINDOW_H
#define POCKET_QTGL_WINDOW_H
#include <QtOpenGL/QGLWidget>
#include "view/GraphicsAdapter.h"
#include <boost/scoped_ptr.hpp>
#include <QTimer>

namespace pocket
{
namespace view
{
	class Scene;
}
class QtGLWindow : public QGLWidget
{
	Q_OBJECT
public:
	QtGLWindow(QWidget *parents = 0);
	~QtGLWindow();

private:
	virtual void initializeGL();
	virtual void resizeGL(int width, int height);
	virtual void paintGL();

private:
	boost::scoped_ptr<view::Scene> scene_;
	view::GraphicsAdapter &graphic_;
	boost::scoped_ptr<QTimer> paint_timer_;
};
} // namespace pocket

#endif
