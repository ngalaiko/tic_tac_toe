TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tic_tac_toe.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tic_tac_toe.h \
    easy.h \
    medium.h \
    hard.h

