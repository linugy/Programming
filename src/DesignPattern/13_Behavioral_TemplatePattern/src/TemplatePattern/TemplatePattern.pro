#-------------------------------------------------
#
# Project created by QtCreator 2022-04-08T09:49:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TemplatePattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    template.cpp \
    subclass1.cpp \
    subclass2.cpp

HEADERS  += mainwindow.h \
    template.h \
    subclass1.h \
    subclass2.h

FORMS    += mainwindow.ui
