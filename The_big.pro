QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classdeclare.cpp \
    dialogfail.cpp \
    dialoginfo.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    studentmanage.cpp

HEADERS += \
    classdeclare.h \
    dialogfail.h \
    dialoginfo.h \
    mainwindow.h \
    mainwindow2.h \
    studentmanage.h

FORMS += \
    dialogfail.ui \
    dialoginfo.ui \
    mainwindow.ui \
    mainwindow2.ui \
    studentmanage.ui

TRANSLATIONS += \
    The_big_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
