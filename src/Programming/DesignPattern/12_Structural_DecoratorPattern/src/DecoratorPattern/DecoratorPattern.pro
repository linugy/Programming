#-------------------------------------------------
#
# Project created by QtCreator 2022-04-08T15:55:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DecoratorPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    absclass.cpp \
    subclass.cpp \
    decoratorabsclass.cpp \
    decoratorsubclass.cpp \
    decoratorsubclass2.cpp \
    decoratorsubclass3.cpp

HEADERS  += mainwindow.h \
    absclass.h \
    subclass.h \
    decoratorabsclass.h \
    decoratorsubclass.h \
    decoratorsubclass2.h \
    decoratorsubclass3.h

FORMS    += mainwindow.ui
