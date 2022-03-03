#-------------------------------------------------
#
# Project created by QtCreator 2022-03-03T19:15:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FacadePattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    facade.cpp \
    subsystema.cpp \
    subsystemb.cpp \
    subsystemc.cpp

HEADERS  += mainwindow.h \
    facade.h \
    subsystema.h \
    subsystemb.h \
    subsystemc.h

FORMS    += mainwindow.ui
