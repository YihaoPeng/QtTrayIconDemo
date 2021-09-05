#-------------------------------------------------
#
# Project created by QtCreator 2012-11-06T17:26:49
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = TrayIconDemo
TEMPLATE = app


SOURCES += main.cpp\
        trayicondemo.cpp

HEADERS  += trayicondemo.h

FORMS    += trayicondemo.ui

RESOURCES += \
    res.qrc

msvc: QMAKE_CXXFLAGS += -source-charset:utf-8
