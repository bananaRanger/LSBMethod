#-------------------------------------------------
#
# Project created by QtCreator 2016-07-06T13:42:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LSBMethodApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lsbencrypt.cpp \
    lsbdecrypt.cpp

HEADERS  += mainwindow.h \
    lsbencrypt.h \
    lsbdecrypt.h

FORMS    += mainwindow.ui
