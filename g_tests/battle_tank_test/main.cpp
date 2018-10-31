#ifndef MAIN_CPP
#define MAIN_CPP

#include "tst_test.h"

#include <gtest/gtest.h>

#include "user_test.h"
#include "unit_test.h"
#include "player_test.h"
#include "map_test.h"
#include "bonus_test.h"
#include "battleground_test.h"
#include "dynamic_room_parameters_tests.h"
#include "bonuscontrol_test.h"

// Если вносите правки в тесты, то удалите отсюда инклуд, запустите, а
// потом снова добавьте инклуд. Без этого гуглотесты не обновляются

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif


