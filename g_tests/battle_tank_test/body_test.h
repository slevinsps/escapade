#ifndef BODY_TEST_H
#define BODY_TEST_H
#include <gtest/gtest.h>
#include "../../battle_tank/body.h"
#include "../../battle_tank/rotational_movement.h"
#include "../../battle_tank/bonus.h"

class BodyTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        QImage texture = QImage("default.png");
        Bonus bonus = Bonus(10,2);
        Bonus bonus_2 = Bonus(10,1);
        body = new Body(Position(), 100, 20, 0, "body", texture);
    }
    void TearDown()
    {
        delete body;
    }
    Body* body;
    Bonus bonus;
    Bonus bonus_2;
};

TEST_F(BodyTest, Create)
{
    EXPECT_EQ(body->get_health(), 100);
    EXPECT_EQ(body->get_max_health(), 100);
    EXPECT_EQ(body->get_rotation_movenent(), RotateMovement(20,0));
}

TEST_F(BodyTest, DecrHealth)
{
    body->decrement_helth(10);
    EXPECT_EQ(body->get_health(), 90);
}

TEST_F(BodyTest, DecrHealthOverflow)
{
    body->decrement_helth(1000);
    EXPECT_EQ(body->get_health(), 0);
}

TEST_F(BodyTest, IncrHealth)
{
    body->increment_helth(50);
    EXPECT_EQ(body->get_health(), 50);
}

TEST_F(BodyTest, IncrHealthOverflow)
{
    body->increment_helth(1000);
    EXPECT_EQ(body->get_health(), 100);
}

TEST_F(BodyTest, ApplyHealthBonus)
{
    body->decrement_helth(10);
    body->apply_health_bonus(bonus);
    EXPECT_EQ(body->get_health(), 100);
}

TEST_F(BodyTest, ApplyHealthBonusOverflow)
{
    body->apply_health_bonus(bonus);
    EXPECT_EQ(body->get_health(), 100);
}

TEST_F(BodyTest, ApplySpeedBonus)
{
    body->get_forward_movement().set_max_speed(0);
    body->apply_speed_bonus(bonus_2);
    EXPECT_EQ(body->get_forward_movement().get_max_speed(), 10);
}

TEST_F(BodyTest, ApplySpeedBonusOverflow)
{
    body->get_forward_movement().set_max_speed(50);
    body->apply_speed_bonus(bonus_2);
    EXPECT_EQ(body->get_forward_movement().get_max_speed(), 50);
}

#endif // BODY_TEST_H
