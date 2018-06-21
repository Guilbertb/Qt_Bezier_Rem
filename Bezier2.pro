#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T21:59:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bezier2
TEMPLATE = app


SOURCES += main.cpp\
        bzmainwindow.cpp \
    bzview.cpp

HEADERS  += bzmainwindow.h \
    bzview.h \
    ../build-Bezier2-Desktop_Qt_5_4_1_MinGW_32bit-Debug/ui_bzmainwindow.h

FORMS    += bzmainwindow.ui

RESOURCES += \
    bzmainwindow.qrc
