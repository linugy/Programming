#-------------------------------------------------
#
# Project created by QtCreator 2022-02-25T14:34:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleFactoryPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    product.cpp \
    producta.cpp \
    productb.cpp \
    factory.cpp

HEADERS  += mainwindow.h \
    product.h \
    producta.h \
    productb.h \
    factory.h

FORMS    += mainwindow.ui
