#-------------------------------------------------
#
# Project created by QtCreator 2018-11-26T08:50:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphDrawing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vertice.cpp \
    graph.cpp \
    mygraphicsview.cpp \
    edge.cpp \
    eades.cpp \
    util.cpp \
    setuptree.cpp

HEADERS  += mainwindow.h \
    vertice.h \
    graph.h \
    mygraphicsview.h \
    edge.h \
    eades.h \
    node.hpp \
    extreme.hpp \
    util.h \
    setuptree.hpp

FORMS    += mainwindow.ui

DISTFILES += \
    tree.txt \
    graph.txt
