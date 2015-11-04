QT       += core
QT       -= gui

TARGET = example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../qtcsv/src/include
LIBS += -lqtcsv

unix {
    LIBS += -L../qtcsv/src
}

SOURCES += main.cpp
