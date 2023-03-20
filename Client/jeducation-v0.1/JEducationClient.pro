QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    ask.cpp \
    choosemode.cpp \
    dialog.cpp \
    info.cpp \
    learning.cpp \
    main.cpp \
    mainwindow.cpp \
    other_questions.cpp

HEADERS += \
    Controller/controller.h \
    ask.h \
    choosemode.h \
    dataTypes.h \
    dialog.h \
    info.h \
    learning.h \
    mainwindow.h \
    other_questions.h

FORMS += \
    ask.ui \
    choosemode.ui \
    dialog.ui \
    info.ui \
    learning.ui \
    mainwindow.ui \
    other_questions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
