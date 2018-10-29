#-------------------------------------------------
#
# Project created by QtCreator 2018-10-28T17:13:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battle_tank3
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
    battleground.cpp \
    body.cpp \
    bonus.cpp \
    bonuscontrol.cpp \
    bullet.cpp \
    component.cpp \
    dynamic_room_parameters.cpp \
    engine.cpp \
    forwardmovement.cpp \
    loader.cpp \
    lobby.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    movement.cpp \
    player.cpp \
    room.cpp \
    rotational_movement.cpp \
    scene.cpp \
    sceneobject.cpp \
    socket.cpp \
    tank.cpp \
    unit.cpp \
    user.cpp \
    weapon.cpp \
    static_room_parameters.cpp \
    user_control_bundle.cpp \
    visualizer.cpp

HEADERS += \
    battleground.h \
    body.h \
    bonus.h \
    bonuscontrol.h \
    bullet.h \
    component.h \
    dynamic_room_parameters.h \
    engine.h \
    forward_movement.h \
    loader.h \
    lobby.h \
    mainwindow.h \
    map.h \
    movement.h \
    player.h \
    room.h \
    rotational_movement.h \
    scene.h \
    sceneobject.h \
    socket.h \
    static_room_parameters.h \
    tank.h \
    unit.h \
    unit_control.h \
    user.h \
    user_control_bundle.h \
    visualizer.h \
    weapon.h \
    socket_include.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
