#-------------------------------------------------
#
# Project created by QtCreator 2022-04-11T13:44:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommandPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    invoke.cpp \
    command.cpp \
    concretecommand.cpp \
    receive.cpp

HEADERS  += mainwindow.h \
    invoke.h \
    command.h \
    concretecommand.h \
    receive.h

FORMS    += mainwindow.ui
