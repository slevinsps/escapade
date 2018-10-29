include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_test.h \
    movement_test.h \
    rot_movement_test.h \
    forward_movement_test.h \
    sceneobject_test.h \
    body_test.h \
    weapon_tests.h \
    bullet_test.h \
    battleground_test.h \
    body_test.h \
    bonus_test.h \
    bonuscontrol_test.h \
    bullet_test.h \
    forward_movement_test.h \
    map_test.h \
    movement_test.h \
    player_test.h \
    rot_movement_test.h \
    scene_test.h \
    sceneobject_test.h \
    tank_test.h \
    tst_test.h \
    unit_test.h \
    user_test.h \
    visualizer_test.h \
    weapon_tests.h \
    dynamic_room_parameters_tests.h \
    static_room_parameters.h

SOURCES +=     main.cpp
