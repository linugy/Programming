#-------------------------------------------------
#
# Project created by QtCreator 2022-04-23T14:01:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediatorPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mediator.cpp \
    concretemediator.cpp \
    colleague.cpp \
    concretecolleague1.cpp \
    concretecolleague2.cpp

HEADERS  += mainwindow.h \
    mediator.h \
    concretemediator.h \
    colleague.h \
    concretecolleague1.h \
    concretecolleague2.h

FORMS    += mainwindow.ui
