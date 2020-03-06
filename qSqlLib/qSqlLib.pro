#-------------------------------------------------
#
# Project created by QtCreator 2019-10-15T13:40:25
#
#-------------------------------------------------

QT       +=  network sql

TARGET = qSqlLib
TEMPLATE = lib

DEFINES += QSQLLIB_LIBRARY

SOURCES += qsqllib.cpp

HEADERS += qsqllib.h\
        qsqllib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
