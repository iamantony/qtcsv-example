QT += core
QT -= gui

TARGET = example
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

unix|win32: LIBS += -L$$OUT_PWD/../qtcsv/src/ -lqtcsv
INCLUDEPATH += $$PWD/../qtcsv/src/include
DEPENDPATH += $$PWD/../qtcsv/src
DESTDIR = $$PWD

win32 {
    install_it.path = $$OUT_PWD
    install_it.files += $$OUT_PWD/../qtcsv/src/qtcsv.dll

    INSTALLS += install_it
}

SOURCES += main.cpp
