QT += core
QT -= gui

CONFIG += c++11

TARGET = MyStack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mystack.cpp

HEADERS += \
    mystack.h
