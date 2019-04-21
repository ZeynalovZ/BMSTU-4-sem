TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_container.cpp \
    exceptions.cpp

HEADERS += \
    base_container.h \
    base_iterator.h \
    matrix.h \
    matrix_implementation.h \
    base_iterator_implementation.h \
    exceptions.h
