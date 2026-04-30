QT += core
QT += network
QT -= gui

TARGET = Tcp_SocketBasic
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sockettest.cpp

HEADERS += \
    sockettest.h

