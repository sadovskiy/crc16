#-------------------------------------------------
#
# Project created by QtCreator 2016-07-30T14:53:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crc16
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    crc16modbus.cpp

HEADERS  += mainwindow.hpp \
    crc16modbus.hpp

FORMS    += mainwindow.ui
