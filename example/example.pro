QT += core
QT -= gui

TARGET = example
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

!msvc {
    # flags for gcc-like compiler
    CONFIG += warn_on
    QMAKE_CXXFLAGS_WARN_ON += -Werror -Wformat=2 -Wuninitialized -Winit-self \
            -Wmissing-include-dirs -Wswitch-enum -Wundef -Wpointer-arith \
            -Wdisabled-optimization -Wcast-align -Wcast-qual
}

# set where linker could find qtcsv library. By default we expect
# that library is located in the same directory as the qtcsv_example binary.
QTCSV_LOCATION = $$OUT_PWD
LIBS += -L$$QTCSV_LOCATION -lqtcsv

INCLUDEPATH += $$PWD/../qtcsv/include

SOURCES += main.cpp

win32 {
    install_it.path = $$OUT_PWD
    install_it.files += $$OUT_PWD/../qtcsv/qtcsv.dll

    INSTALLS += install_it
}

DISTFILES += \
    CMakeLists.txt

message(=== Configuration of example ===)
message(Qt version: $$[QT_VERSION])
message(example binary will be created in folder: $$OUT_PWD)
