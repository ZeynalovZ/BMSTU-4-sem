TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stream_worker.cpp \
    math_module.cpp

HEADERS += \
    stream_worker.h \
    errors.h \
    math_module.h

DISTFILES += \
    data.txt
