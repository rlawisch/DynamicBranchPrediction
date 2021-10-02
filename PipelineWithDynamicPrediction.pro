QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    addi.cpp \
    b.cpp \
    beq.cpp \
    fileparser.cpp \
    main.cpp \
    mainwindow.cpp \
    pipeline.cpp \
    programcounter.cpp \
    programmemory.cpp \
    registerbank.cpp \
    sub.cpp \
    subi.cpp

HEADERS += \
    add.h \
    addi.h \
    b.h \
    beq.h \
    fileparser.h \
    instruction.h \
    mainwindow.h \
    pipeline.h \
    programcounter.h \
    programmemory.h \
    registerbank.h \
    sub.h \
    subi.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
