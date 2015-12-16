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
    src/instwizard.cpp \
    src/wifistartup.cpp \
    src/wifisetup.cpp

HEADERS  += src/kndiswrapper.h \
    src/wikilookup.h \
    src/instwizard.h \
    src/wifistartup.h \
    src/wifisetup.h

FORMS    += ui/kndiswrapper.ui \
    ui/wikilookup.ui \
    ui/instwizard.ui \
    ui/wifistartup.ui \
    ui/wifisetup.ui

RESOURCES += icons.qrc

TRANSLATIONS += translations/kndiswrapper_en.ts \
    translations/kndiswrapper_de.ts \
    translations/kndiswrapper_ru.ts \
    translations/kndiswrapper_zh_CN.ts

OTHER_FILES += \
    translations/kndiswrapper_en.ts \
    translations/kndiswrapper_zh_CN.ts \
    translations/kndiswrapper_ru.ts \
    translations/kndiswrapper_de.ts




























