#-------------------------------------------------
#
# Project created by QtCreator 2022-04-23T15:59:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterpreterPattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    context.cpp \
    expression.cpp \
    multiexpression.cpp \
    divexpression.cpp \
    termimalexpression.cpp

HEADERS  += mainwindow.h \
    context.h \
    expression.h \
    multiexpression.h \
    divexpression.h \
    termimalexpression.h

FORMS    += mainwindow.ui
