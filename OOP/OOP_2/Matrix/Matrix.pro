TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_container.cpp \
    matrix.cpp

HEADERS += \
    matrix.h \
    matrix_implementation.h \
    excepctions.h \
    base_container.h
