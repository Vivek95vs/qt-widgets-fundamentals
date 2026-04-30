QT += core
QT += network
QT -= gui

TARGET = Signal_and_Slot_Tcp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    socketsas.cpp

HEADERS += \
    socketsas.h

