TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

QMAKE_CFLAGS += -O0

include(../fiol.pri)
