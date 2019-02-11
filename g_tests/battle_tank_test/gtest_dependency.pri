isEmpty(GOOGLETEST_DIR):GOOGLETEST_DIR=$$(GOOGLETEST_DIR)

isEmpty(GOOGLETEST_DIR) {
    warning("Using googletest src dir specified at Qt Creator wizard")
    message("set GOOGLETEST_DIR as environment variable or qmake variable to get rid of this message")
    GOOGLETEST_DIR = D:/googletest-master
}

!isEmpty(GOOGLETEST_DIR): {
    GTEST_SRCDIR = $$GOOGLETEST_DIR/googletest
    GMOCK_SRCDIR = $$GOOGLETEST_DIR/googlemock
}

requires(exists($$GTEST_SRCDIR):exists($$GMOCK_SRCDIR))

!exists($$GOOGLETEST_DIR):message("No googletest src dir found - set GOOGLETEST_DIR to enable.")

DEFINES += \
    GTEST_LANG_CXX11

INCLUDEPATH *= \
    $$GTEST_SRCDIR \
    $$GTEST_SRCDIR/include \
    $$GMOCK_SRCDIR \
    $$GMOCK_SRCDIR/include

SOURCES += \
    $$GTEST_SRCDIR/src/gtest-all.cc \
    $$GMOCK_SRCDIR/src/gmock-all.cc \
    $$PWD/../../battle_tank/bullet.cpp \
    $$PWD/../../battle_tank/component.cpp \
    $$PWD/../../battle_tank/dynamic_room_parameters.cpp \
    $$PWD/../../battle_tank/forward_movement.cpp \
    $$PWD/../../battle_tank/loader.cpp \
    $$PWD/../../battle_tank/lobby.cpp \
    $$PWD/../../battle_tank/map.cpp \
    $$PWD/../../battle_tank/movement.cpp \
    $$PWD/../../battle_tank/player.cpp \
    $$PWD/../../battle_tank/room.cpp \
    $$PWD/../../battle_tank/rotational_movement.cpp \
    $$PWD/../../battle_tank/scene.cpp \
    $$PWD/../../battle_tank/sceneobject.cpp \
    $$PWD/../../battle_tank/socket.cpp \
    $$PWD/../../battle_tank/static_room_parameters.cpp \
    $$PWD/../../battle_tank/tank.cpp \
    $$PWD/../../battle_tank/unit.cpp \
    $$PWD/../../battle_tank/user.cpp \
    $$PWD/../../battle_tank/weapon.cpp \
    $$PWD/../../battle_tank/user_control_bundle.cpp \
    $$PWD/../../battle_tank/visualizer.cpp \
    $$PWD/../../battle_tank/bonus.cpp \
    $$PWD/../../battle_tank/battleground.cpp \
    $$PWD/../../battle_tank/bonuscontrol.cpp

HEADERS += \
    $$PWD/../../battle_tank/base_visualizer.h \
    $$PWD/../../battle_tank/baseunitcontrol.h \
    $$PWD/../../battle_tank/battleground.h \
    $$PWD/../../battle_tank/body.h \
    $$PWD/../../battle_tank/bonus.h \
    $$PWD/../../battle_tank/bonuscontrol.h \
    $$PWD/../../battle_tank/bullet.h \
    $$PWD/../../battle_tank/component.h \
    $$PWD/../../battle_tank/dynamic_room_parameters.h \
    $$PWD/../../battle_tank/engine.h \
    $$PWD/../../battle_tank/forward_movement.h \
    $$PWD/../../battle_tank/forwardmovement.h \
    $$PWD/../../battle_tank/loader.h \
    $$PWD/../../battle_tank/lobby.h \
    $$PWD/../../battle_tank/mainwindow.h \
    $$PWD/../../battle_tank/map.h \
    $$PWD/../../battle_tank/movement.h \
    $$PWD/../../battle_tank/network.h \
    $$PWD/../../battle_tank/player.h \
    $$PWD/../../battle_tank/room.h \
    $$PWD/../../battle_tank/rotational_movement.h \
    $$PWD/../../battle_tank/scene.h \
    $$PWD/../../battle_tank/sceneobject.h \
    $$PWD/../../battle_tank/socket.h \
    $$PWD/../../battle_tank/socket_include.h \
    $$PWD/../../battle_tank/static_room_parameters.h \
    $$PWD/../../battle_tank/tank.h \
    $$PWD/../../battle_tank/unit.h \
    $$PWD/../../battle_tank/unit_control.h \
    $$PWD/../../battle_tank/user.h \
    $$PWD/../../battle_tank/user_control_bundle.h \
    $$PWD/../../battle_tank/visualizer.h \
    $$PWD/../../battle_tank/weapon.h \
    $$PWD/../../battle_tank/base_visualizer.h \
    $$PWD/../../battle_tank/baseunitcontrol.h \
    $$PWD/../../battle_tank/body.h \
    $$PWD/../../battle_tank/bullet.h \
    $$PWD/../../battle_tank/component.h \
    $$PWD/../../battle_tank/dynamic_room_parameters.h \
    $$PWD/../../battle_tank/engine.h \
    $$PWD/../../battle_tank/forward_movement.h \
    $$PWD/../../battle_tank/forwardmovement.h \
    $$PWD/../../battle_tank/loader.h \
    $$PWD/../../battle_tank/lobby.h \
    $$PWD/../../battle_tank/map.h \
    $$PWD/../../battle_tank/movement.h \
    $$PWD/../../battle_tank/network.h \
    $$PWD/../../battle_tank/player.h \
    $$PWD/../../battle_tank/room.h \
    $$PWD/../../battle_tank/rotational_movement.h \
    $$PWD/../../battle_tank/scene.h \
    $$PWD/../../battle_tank/sceneobject.h \
    $$PWD/../../battle_tank/socket.h \
    $$PWD/../../battle_tank/socket_include.h \
    $$PWD/../../battle_tank/static_room_parameters.h \
    $$PWD/../../battle_tank/tank.h \
    $$PWD/../../battle_tank/unit.h \
    $$PWD/../../battle_tank/unit_control.h \
    $$PWD/../../battle_tank/user.h \
    $$PWD/../../battle_tank/user_control_bundle.h \
    $$PWD/../../battle_tank/visualizer.h
