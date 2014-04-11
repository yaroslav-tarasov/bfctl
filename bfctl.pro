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
    #netlinksocket.cpp \
    bfcontrol.cpp

HEADERS += \
    #netlinksocket.h \
    bfcontrol.h

INCLUDEPATH += ../bf-ko ../bf-link

LIBS += -lnl

DESTDIR = ../../bin
LIBS += -L../../lib -lbf-link
