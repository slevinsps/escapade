#ifndef FORWARD_MOVEMENT_TEST_H
#define FORWARD_MOVEMENT_TEST_H

#include <gtest/gtest.h>
#include "../../battle_tank/forward_movement.h"

class ForwardMovementTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        move = new ForwardMovement(70,20);
    }
    void TearDown()
    {
        delete move;
    }
    ForwardMovement *move;
};

TEST_F(RotationalMovementTest, Create)
{
    EXPECT_EQ(move->get_current_speed(), 0);
    EXPECT_EQ(move->get_max_speed(), 70);
    EXPECT_EQ(move->get_max_back_speed(), 20);
}

TEST_F(RotationalMovementTest, Setter)
{
    move->set_max_speed(50);
    move->set_current_speed(20);
    move->set_max_back_speed(10);
    EXPECT_EQ(move->get_current_speed(), 20);
    EXPECT_EQ(move->get_max_speed(), 50);
    EXPECT_EQ(move->get_max_back_speed(), 10);
}
#endif // FORWARD_MOVEMENT_TEST_H
