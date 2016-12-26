QT += core
QT -= gui

TARGET = example
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

unix|win32: LIBS += -L$$PWD/../qtcsv/ -lqtcsv
INCLUDEPATH += $$PWD/../qtcsv/include
#DEPENDPATH += $$PWD/../qtcsv/src

# DESTDIR specifies where to put the binary file
CONFIG(release, debug|release): DESTDIR = $$PWD
CONFIG(debug, debug|release): DESTDIR = $$PWD

win32 {
    install_it.path = $$OUT_PWD
    install_it.files += $$OUT_PWD/../qtcsv/qtcsv.dll

    INSTALLS += install_it
}

SOURCES += main.cpp
