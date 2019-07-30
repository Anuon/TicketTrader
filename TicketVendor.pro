#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T21:27:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicketVendor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        createeventwindow.cpp \
        creditsformwindow.cpp \
        databasehandler.cpp \
        event.cpp \
        eventitemwidget.cpp \
        main.cpp \
        loginwindow.cpp \
        mainwindow.cpp \
        registerwindow.cpp \
        user.cpp

HEADERS += \
        createeventwindow.h \
        creditsformwindow.h \
        databasehandler.h \
        event.h \
        eventitemwidget.h \
        loginwindow.h \
        mainwindow.h \
        registerwindow.h \
        user.h

FORMS += \
        createeventwindow.ui \
        creditsformwindow.ui \
        eventitemwidget.ui \
        loginwindow.ui \
        mainwindow.ui \
        registerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
