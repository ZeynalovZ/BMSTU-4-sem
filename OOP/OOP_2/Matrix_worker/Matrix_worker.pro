TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_container.cpp \
    matrix.cpp

HEADERS += \
    matrix.h \
    base_container.h \
    matrix_implementation.h \
    exceptions.h
