#-------------------------------------------------
#
# Project created by QtCreator 2017-01-03T10:36:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += printsupport

TARGET = SimpleLineChartConfigurable
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simplelinechart.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    simplelinechart.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    simplelinechart.ui
