#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T08:07:43
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    thread.h \
    graph.h

FORMS    += mainwindow.ui
