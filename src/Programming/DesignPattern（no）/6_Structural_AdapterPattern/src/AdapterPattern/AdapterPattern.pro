#-------------------------------------------------
#
# Project created by QtCreator 2022-03-03T18:49:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdapterPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adapter.cpp \
    adaptee.cpp \
    target.cpp

HEADERS  += mainwindow.h \
    adapter.h \
    adaptee.h \
    target.h

FORMS    += mainwindow.ui
