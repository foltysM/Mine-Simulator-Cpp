QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abovegroundworker.cpp \
    abovegroundworkeritem.cpp \
    accountant.cpp \
    blackcoalmine.cpp \
    browncoalmine.cpp \
    chair.cpp \
    computer.cpp \
    desk.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    mine.cpp \
    miner.cpp \
    minerhat.cpp \
    mineritem.cpp \
    minerlamp.cpp \
    minersuit.cpp \
    mixedcoalmine.cpp \
    newminerslist.cpp \
    newmonthdialog.cpp \
    notweatherdependentcompany.cpp \
    officeworker.cpp \
    storage.cpp \
    weatherdependent.cpp

HEADERS += \
    abovegroundworker.h \
    abovegroundworkeritem.h \
    accountant.h \
    blackcoalmine.h \
    browncoalmine.h \
    chair.h \
    computer.h \
    desk.h \
    game.h \
    mainwindow.h \
    mine.h \
    miner.h \
    minerhat.h \
    mineritem.h \
    minerlamp.h \
    minersuit.h \
    mixedcoalmine.h \
    newminerslist.h \
    newmonthdialog.h \
    notweatherdependentcompany.h \
    officeworker.h \
    storage.h \
    weatherdependent.h

FORMS += \
    mainwindow.ui \
    newmonthdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    D:/GDrive/Notatki/PJC/moje/Projekt/pliki programu/bru100.png \
    D:/GDrive/Notatki/PJC/moje/Projekt/pliki programu/kam100.png \
    D:/GDrive/Notatki/PJC/moje/Projekt/pliki programu/ur100.png

RESOURCES += \
    res.qrc
