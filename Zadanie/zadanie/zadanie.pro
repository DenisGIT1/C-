QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    fileprocessor.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    fileprocessor.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS +=
CONFIG += lrelease
CONFIG += embed_translations

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
