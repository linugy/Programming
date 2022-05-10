#-------------------------------------------------
#
# Project created by QtCreator 2022-04-08T14:54:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CompositePattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    component.cpp \
    composite.cpp \
    leaf.cpp

HEADERS  += mainwindow.h \
    component.h \
    composite.h \
    leaf.h

FORMS    += mainwindow.ui
