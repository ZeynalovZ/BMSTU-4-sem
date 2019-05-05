TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    math_module.cpp

DISTFILES += \
    readme.md \
    input.txt

HEADERS += \
    math_module.h
