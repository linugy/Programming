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
    factory.cpp \
    factorya.cpp \
    factoryb.cpp \
    product2.cpp \
    product2a.cpp \
    product2b.cpp

HEADERS  += mainwindow.h \
    product.h \
    producta.h \
    productb.h \
    factory.h \
    factorya.h \
    factoryb.h \
    product2.h \
    product2a.h \
    product2b.h

FORMS    += mainwindow.ui
