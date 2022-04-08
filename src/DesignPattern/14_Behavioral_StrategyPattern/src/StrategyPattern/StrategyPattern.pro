#-------------------------------------------------
#
# Project created by QtCreator 2022-04-08T10:32:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StrategyPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    absclass.cpp \
    subclass1.cpp \
    subclass2.cpp \
    absfunclass.cpp \
    funclass1.cpp \
    funclass2.cpp

HEADERS  += mainwindow.h \
    absclass.h \
    subclass1.h \
    subclass2.h \
    absfunclass.h \
    funclass1.h \
    funclass2.h

FORMS    += mainwindow.ui
