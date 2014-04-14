#include<QtGui/QApplication>
#include "QtGLWindow.h"
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	pocket::QtGLWindow window;
	window.setWindowTitle(QObject::tr("Pocket Client"));
	window.resize(1366, 768);
	window.show();
	return app.exec();
}
