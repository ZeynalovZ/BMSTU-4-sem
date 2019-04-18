TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_container.cpp \
    matrix.cpp \
    exceptions.cpp

HEADERS += \
    matrix.h \
    matrix_implementation.h \
    excepctions.h \
    base_container.h \
    base_iterator.h \
    base_iterator_implementation.h \
    matrix_iterator.h \
    const_matrix_iterator.h \
    matrix_iterator_implementation.h \
    const_matrix_iterator_implementation.h
