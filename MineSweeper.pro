#-------------------------------------------------
#
# Project created by QtCreator 2014-07-08T19:31:30
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineSweeper
TEMPLATE = app

#RC_FILE = MineSweeper.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    board.cpp \
    minesweeperconstruction.cpp \
    solvingminesweeper.cpp \
    toolbar.cpp \
    timer.cpp \
    settings.cpp \
    preference.cpp \
    howtoplay.cpp \
    highscores.cpp \
    about.cpp \
    newgame.cpp \
    newgamewindow.cpp \
    newscore.cpp \
    qmouseclickbuttons.cpp \
    impfiles.cpp

HEADERS  += mainwindow.h \
    board.h \
    minesweeperconstruction.h \
    solvingminesweeper.h \
    toolbar.h \
    timer.h \
    settings.h \
    preference.h \
    howtoplay.h \
    highscores.h \
    about.h \
    newgame.h \
    newgamewindow.h \
    newscore.h \
    qmouseclickbuttons.h \
    impfiles.h

RESOURCES += \
    Resources.qrc
