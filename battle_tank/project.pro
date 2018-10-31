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
    bonus.cpp \
    unit.cpp \
    tank.cpp \
    weapon.cpp \
    bullet.cpp \
    sceneobject.cpp \
    component.cpp \
    body.cpp \
    scene.cpp \
    bonuscontrol.cpp \
    movement.cpp \
    user.cpp \
    player.cpp \
    room.cpp \
    lobby.cpp \
    socket.cpp \
    loader.cpp \
    rotational_movement.cpp \
    main.cpp \
    mainwindow.cpp \
    battleground.cpp \
    dynamic_room_parameters.cpp \
    static_room_parameters.cpp \
    user_control_bundle.cpp \
    visualizer.cpp \
    forward_movement.cpp \
    map.cpp

HEADERS += \
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
    user.h \
    player.h \
    map.h \
    room.h \
    lobby.h \
    network.h \
    socket.h \
    loader.h \
    rotational_movement.h \
    battleground.h \
    dynamic_room_parameters.h \
    forward_movement.h \
    mainwindow.h \
    network.h \
    scene.h \
    static_room_parameters.h \
    visualizer.h \
    user_control_bundle.h \
    base_visualizer.h \
    baseunitcontrol.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
