#-------------------------------------------------
#
# Project created by QtCreator 2014-04-09T17:16:19
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = bfctl
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    netlinksocket.cpp

HEADERS += \
    netlinksocket.h

LIBS += -lnl
