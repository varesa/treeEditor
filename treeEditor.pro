#-------------------------------------------------
#
# Project created by QtCreator 2015-02-25T19:35:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = treeEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filewrapper.cpp \
    jsonimport.cpp \
    jsonexport.cpp

HEADERS  += mainwindow.h \
    filewrapper.h \
    jsonimport.h \
    jsonexport.h

FORMS    += mainwindow.ui
