QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#Set variables
QUAZIPCODEDIR = "/home/ali/Downloads/quazip-0.7.3/quazip"
ZLIBCODEDIR = "/home/ali/Downloads/Libs"

#include the compiled code

unix {
  LIBS += -L$${ZLIBCODEDIR} -lz
}

win32 {
   LIBS += -L$${ZLIBCODEDIR} -lzdll

}
#incldue files
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += $${QUAZIPCODEDIR}/*.h \
    DataBaseConnection.h \
    FileFormat.h \
    SeperatingNameIntoPieces.h \
    SeperatingNameIntoPieces.h \
    ZippingProcess.h \
    ZippingProcess.h
SOURCES += $${QUAZIPCODEDIR}/*.cpp \
    DataBaseConnection.cpp \
    DirectoryRevision.cpp \
    FileFormat.cpp \
    SeperatingNameIntoPieces.cpp \
    SeperatingNameIntoPieces.cpp \
    ZippingProcess.cpp \
    ZippingProcess.cpp
SOURCES += $${QUAZIPCODEDIR}/*.c




SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Image.qrc
