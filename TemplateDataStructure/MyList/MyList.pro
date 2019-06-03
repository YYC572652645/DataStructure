QT += core
QT -= gui

CONFIG += c++11

TARGET = MyList
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mylist.cpp

HEADERS += \
    mylist.h
