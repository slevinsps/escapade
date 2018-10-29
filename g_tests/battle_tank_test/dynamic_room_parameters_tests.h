#ifndef DYNAMIC_ROOM_PARAMETERS_TESTS_H
#define DYNAMIC_ROOM_PARAMETERS_TESTS_H

#include <gtest/gtest.h>
#include "../../battle_tank/dynamic_room_parameters.h"

class DynamicRoomParametersTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        param = new DynamicRoomParameters();
    }
    void TearDown()
    {
        delete param;
    }
    DynamicRoomParameters* param;
};

TEST_F(DynamicRoomParametersTest, Setter)
{
    param->set_amount_of_players(3);
    param->set_status(1);
    param->set_amount_of_matches(10);
    EXPECT_EQ(param->get_amount_of_players(), 3);
    EXPECT_EQ(param->get_status(), 1);
    EXPECT_EQ(param->get_amount_of_matches(), 10);
}
#endif // DYNAMIC_ROOM_PARAMETERS_TESTS_H
