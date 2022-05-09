#-------------------------------------------------
#
# Project created by QtCreator 2022-04-23T10:28:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MementoPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    role.cpp \
    memento.cpp \
    manager.cpp

HEADERS  += mainwindow.h \
    role.h \
    memento.h \
    manager.h

FORMS    += mainwindow.ui
