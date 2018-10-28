#ifndef MOVEMENT_TEST_H
#define MOVEMENT_TEST_H

#include <gtest/gtest.h>
#include "../../battle_tank/movement.h"

class MovementTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        move = new Movement(70, 0);
    }
    void TearDown()
    {
        delete move;
    }
    Movement *move;
};

TEST_F(MovementTest, Create)
{
    EXPECT_EQ(move->get_current_speed(), 0);
    EXPECT_EQ(move->get_max_speed(), 70);
}

TEST_F(MovementTest, Setter)
{
    move->set_max_speed(50);
    move->set_current_speed(20);
    EXPECT_EQ(move->get_current_speed(), 20);
    EXPECT_EQ(move->get_max_speed(), 50);
}

#endif // MOVEMENT_TEST_H
