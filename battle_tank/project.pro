#-------------------------------------------------
#
# Project created by QtCreator 2018-10-16T22:24:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
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
        main.cpp \
        mainwindow.cpp \
    bonus.cpp \
    unit.cpp \
    tank.cpp \
    weapon.cpp \
    bullet.cpp \
    sceneobject.cpp \
    component.cpp \
    engine.cpp \
    body.cpp \
    scene.cpp \
    bonuscontrol.cpp \
    tank_control.cpp \
    movement.cpp \
    forwardmovement.cpp \
    rotationalmotion.cpp \
    user.cpp \
    player.cpp \
    map.cpp \
    room.cpp \
    lobby.cpp \
    client.cpp \
    user_control.cpp \
    socket.cpp \
    loader.cpp \
    rotational_movement.cpp \
    body.cpp \
    bonus.cpp \
    bonuscontrol.cpp \
    bullet.cpp \
    component.cpp \
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
    user_control.cpp \
    weapon.cpp

HEADERS += \
        mainwindow.h \
    bonus.h \
    unit.h \
    tank.h \
    weapon.h \
    bullet.h \
    sceneobject.h \
    component.h \
    body.h \
    scene.h \
    bonuscontrol.h \
    unit_control.h \
    movement.h \
    rotationalmotion.h \
    user.h \
    player.h \
    map.h \
    room.h \
    lobby.h \
    client.h \
    network.h \
    socket.h \
    loader.h \
    rotational_movement.h \
    battleground.h \
    body.h \
    bonus.h \
    bonuscontrol.h \
    bullet.h \
    component.h \
    dynamic_room_parameters.h \
    forward_movement.h \
    loader.h \
    lobby.h \
    mainwindow.h \
    map.h \
    movement.h \
    network.h \
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
    visualizer.h \
    weapon.h \
    user_control_bundle.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
