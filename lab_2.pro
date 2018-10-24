QT +=core gui
QT +=opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl
TEMPLATE = app

LIBS += -lOpengl32

SOURCES += main.cpp \
    mainwindow.cpp \
    miwidget.cpp

HEADERS += \
    mainwindow.h \
    miwidget.h

FORMS += \
    mainwindow.ui \
    mainwindow.ui


