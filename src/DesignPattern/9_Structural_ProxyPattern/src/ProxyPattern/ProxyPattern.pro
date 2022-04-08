#-------------------------------------------------
#
# Project created by QtCreator 2022-04-08T11:38:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProxyPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    absclass.cpp \
    subclass.cpp \
    proxyclass.cpp

HEADERS  += mainwindow.h \
    absclass.h \
    subclass.h \
    proxyclass.h

FORMS    += mainwindow.ui
