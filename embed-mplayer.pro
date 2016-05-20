#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T16:16:27
#
#-------------------------------------------------

QT       += core gui x11extras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = embed-mplayer
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += x11

SOURCES += main.cpp\
        container.cpp

HEADERS  += container.h
