#-------------------------------------------------
#
# Project created by QtCreator 2020-02-19T20:22:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = afuberechnung
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

CONFIG += qt warn_off release debug

SOURCES += \
    afuberechnungamateurfunkbaender.cpp \
    afuberechnungeinstellungen.cpp \
    afuberechnungresotrans.cpp \
    afuberechnungwattdbm.cpp \
        afuberechnung.cpp \
    afuberechnungfrequenz.cpp \
    afuberechnungkapazitaet.cpp \
    afuberechnunginduktivitaet.cpp \
    afuberechnungverlaengerungsspule.cpp \
    afuberechnungdrahtlaenge.cpp \
    afuberechnungluftspule.cpp \
    afuberechnungtrapantenne.cpp \
    afuberechnunganzeigefrequenz.cpp \
    afuberechnungwiderstand.cpp

HEADERS += \
        afuberechnung.h \
    afuberechnungamateurfunkbaender.h \
    afuberechnungeinstellungen.h \
    afuberechnungfrequenz.h \
    afuberechnungkapazitaet.h \
    afuberechnunginduktivitaet.h \
    afuberechnungresotrans.h \
    afuberechnungverlaengerungsspule.h \
    afuberechnungdrahtlaenge.h \
    afuberechnungluftspule.h \
    afuberechnungtrapantenne.h \
    afuberechnunganzeigefrequenz.h \
    afuberechnungwattdbm.h \
    afuberechnungwiderstand.h

FORMS +=

