#-------------------------------------------------
#
# Project created by QtCreator 2022-04-08T19:25:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ObserverPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subject.cpp \
    concretesubject.cpp \
    observe.cpp \
    concreteobserve.cpp \
    concreteobserve2.cpp

HEADERS  += mainwindow.h \
    subject.h \
    concretesubject.h \
    observe.h \
    concreteobserve.h \
    concreteobserve2.h

FORMS    += mainwindow.ui
