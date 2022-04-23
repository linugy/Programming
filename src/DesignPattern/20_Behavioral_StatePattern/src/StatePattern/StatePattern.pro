#-------------------------------------------------
#
# Project created by QtCreator 2022-04-23T15:12:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StatePattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    context.cpp \
    state.cpp \
    concretestate1.cpp \
    concretestate2.cpp

HEADERS  += mainwindow.h \
    context.h \
    state.h \
    concretestate1.h \
    concretestate2.h

FORMS    += mainwindow.ui
