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
    uiutils.cpp \
    messagewrapper.cpp \
    parser.cpp

HEADERS  += mainwindow.h \
    uiutils.h \
    messagewrapper.h \
    parser.h

FORMS    += mainwindow.ui
