QT += core
QT += network
QT -= gui

TARGET = To_Make_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp

HEADERS += \
    myserver.h

