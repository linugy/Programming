#-------------------------------------------------
#
# Project created by QtCreator 2022-03-03T17:16:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SingletonPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    singleton.cpp

HEADERS  += mainwindow.h \
    singleton.h

FORMS    += mainwindow.ui
