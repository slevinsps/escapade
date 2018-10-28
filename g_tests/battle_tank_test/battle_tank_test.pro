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
    bullet_test.h

SOURCES +=     main.cpp
