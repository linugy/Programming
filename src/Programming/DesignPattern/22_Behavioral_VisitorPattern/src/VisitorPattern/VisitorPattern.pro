#-------------------------------------------------
#
# Project created by QtCreator 2022-05-09T14:29:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisitorPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectstructure.cpp \
    visitor.cpp \
    visitora.cpp \
    visitorb.cpp \
    element.cpp \
    elementa.cpp \
    elementb.cpp

HEADERS  += mainwindow.h \
    objectstructure.h \
    visitor.h \
    visitora.h \
    visitorb.h \
    element.h \
    elementa.h \
    elementb.h

FORMS    += mainwindow.ui
