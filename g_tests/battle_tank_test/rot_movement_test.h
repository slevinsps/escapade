#ifndef ROT_MOVEMENT_TEST_H
#define ROT_MOVEMENT_TEST_H
#include <gtest/gtest.h>
#include "../../battle_tank/rotational_movement.h"
#include "../../battle_tank/rotational_movement.cpp"

class RotationalMovementTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        move = new RotateMovement(70,10);
    }
    void TearDown()
    {
        delete move;
    }
    RotateMovement *move;
};

TEST_F(RotationalMovementTest, Create)
{
    EXPECT_EQ(move->get_current_speed(), 0);
    EXPECT_EQ(move->get_max_speed(), 70);
    EXPECT_EQ(move->get_current_angle(), 10);
}

TEST_F(RotationalMovementTest, Setter)
{
    move->set_max_speed(50);
    move->set_current_speed(20);
    move->set_current_angle(10);
    EXPECT_EQ(move->get_current_speed(), 20);
    EXPECT_EQ(move->get_max_speed(), 50);
    EXPECT_EQ(move->get_current_angle(), 10);
}
#endif // ROT_MOVEMENT_TEST_H
