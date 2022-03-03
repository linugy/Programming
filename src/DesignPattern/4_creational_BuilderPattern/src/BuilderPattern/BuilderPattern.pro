#-------------------------------------------------
#
# Project created by QtCreator 2022-03-03T17:27:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BuilderPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    product.cpp \
    builder.cpp \
    director.cpp

HEADERS  += mainwindow.h \
    product.h \
    builder.h \
    director.h

FORMS    += mainwindow.ui
