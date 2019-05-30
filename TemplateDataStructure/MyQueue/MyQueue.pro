QT += core
QT -= gui

CONFIG += c++11

TARGET = MyQueue
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myqueue.cpp

HEADERS += \
    myqueue.h
