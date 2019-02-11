#ifndef BULLET_TEST_H
#define BULLET_TEST_H
#include <cmath>
#include <gtest/gtest.h>
#include "../../battle_tank/body.h"
#include "../../battle_tank/rotational_movement.h"
#include "../../battle_tank/bullet.h"

class BulletTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        bullet = new Bullet(Position(1,2));
    }
    void TearDown()
    {
        delete body;
    }
    Bullet* bullet;
    Bonus bonus;
};

TEST_F(BulletTest, Create)
{
    EXPECT_TRUE(false == bullet->get_islaunch);
    EXPECT_EQ(bullet->get_range(), 0);
}


TEST_F(BulletTest, CountRange)
{
    ASSERT_FLOAT_EQ(bullet->count_range, sqrt(5));
}

TEST_F(BulletTest, Move)
{
    EXPECT_EQ(bullet->move, 0);
}



#endif // BULLET_TEST_H
