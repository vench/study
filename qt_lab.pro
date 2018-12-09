#-------------------------------------------------
#
# Project created by QtCreator 2018-11-12T09:14:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_lab
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    glass.cpp \
    figure.cpp

HEADERS  += \
    mainwindow.h \
    glass.h \
    figure.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

TRANSLATIONS += dict_ru.ts

RESOURCES += \
    rc.qrc

RC_ICONS = icon.ico

FORMS += \
    mainwindow.ui
