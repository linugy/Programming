#-------------------------------------------------
#
# Project created by QtCreator 2022-05-09T15:27:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IteratorPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aggregate.cpp \
    iterator.cpp

HEADERS  += mainwindow.h \
    aggregate.h \
    iterator.h

FORMS    += mainwindow.ui
