QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
SOURCES += \
			PocketClient.cc \
			QtGLWindow.cc \
			model/resource.cc \ 
			model/resdata.cc \
			model/card.cc \
			model/config.cc \
			view/GraphicsAdapter.cc \
			view/OpenGLAdapter.cc \
			view/ViewObject.cc \
			view/CardObject.cc \
			view/scene.cc
	
HEADERS += \
			QtGLWindow.h \
			glHeader.h \
			base/singleton.h \
			base/types.h \
			model/card.h \
			model/resdata.h \
			model/resource.h \
			model/config.h \
			view/GraphicsAdapter.h \
			view/OpenGLAdapter.h \
			view/ViewObject.h \
			view/CardObject.h \
			view/scene.h

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -L../lib
INCLUDEPATH += ../include
FORMS += \

LIBS += -llodepng
QT += opengl
CONFIG += qt debug
