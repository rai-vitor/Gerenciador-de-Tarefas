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
    graph.cpp \
    proc.cpp

HEADERS  += mainwindow.h \
    graph.h \
    proc.h

FORMS    += mainwindow.ui
