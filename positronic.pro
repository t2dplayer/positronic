TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        input-reader.cpp \
        main.cpp \
        positronic.cpp \
        string-utils.cpp

HEADERS += \
    data-frame.h \
    header.h \
    input-reader.h \
    parse-options.h \
    positronic.h \
    sparsematrix.h \
    string-utils.h

DISTFILES += \
    car_data.csv \
    input.txt

