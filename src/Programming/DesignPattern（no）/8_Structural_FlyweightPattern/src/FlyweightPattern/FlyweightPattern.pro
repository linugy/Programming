#-------------------------------------------------
#
# Project created by QtCreator 2022-03-03T19:39:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlyweightPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    piece.cpp \
    piecefactory.cpp \
    pieceboard.cpp

HEADERS  += mainwindow.h \
    piece.h \
    piecefactory.h \
    pieceboard.h

FORMS    += mainwindow.ui
