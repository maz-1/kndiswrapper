#-------------------------------------------------
#
# Project created by QtCreator 2012-02-24T07:34:53
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = kndiswrapper
TEMPLATE = app


SOURCES += src/main.cpp\
        src/kndiswrapper.cpp \
    src/wikilookup.cpp \
    src/setupdialog.cpp \
    src/instwizard.cpp \
    src/wifistartup.cpp \
    src/wifisetup.cpp

HEADERS  += src/kndiswrapper.h \
    src/wikilookup.h \
    src/setupdialog.h \
    src/instwizard.h \
    src/wifistartup.h \
    src/wifisetup.h

FORMS    += ui/kndiswrapper.ui \
    ui/wikilookup.ui \
    ui/setupdialog.ui \
    ui/instwizard.ui \
    ui/wifistartup.ui \
    ui/wifisetup.ui

RESOURCES += icons.qrc

TRANSLATIONS += translations/english.ts \
    translations/german.ts \
    translations/russian.ts \
    translations/simplyfied_chinese.ts

OTHER_FILES += \
    translations/english.ts \
    translations/simplyfied_chinese.ts \
    translations/russian.ts \
    translations/german.ts




























