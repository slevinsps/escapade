#ifndef TANK_TEST_H
#define TANK_TEST_H

#include <gtest/gtest.h>
#include "../../battle_tank/rotational_movement.h"
#include "../../battle_tank/tank.h"

class Tanktest : public ::testing::Test
{
protected:
    void SetUp()
    {
        Weapon weapon(Position(0,0));
        Body body(Position(0,0));

        tank = new Tank(weapon, body);
    }
    void TearDown()
    {
        delete tank;
    }
    Tank *tank;
};

TEST_F(Tanktest, Create)
{
    Weapon weapon(Position(0,0));
    Body body(Position(0,0));

    EXPECT_EQ(tank->get_weapon(), weapon);
    EXPECT_EQ(tank->get_body(), body);
}

TEST_F(Tanktest, move)
{
    tank->move(10);
    Position rightPosition(10,10);
    EXPECT_EQ(tank->getPosition(), rightPosition);
}

TEST_F(Tanktest, rotate)
{
    double angle = 10;
    tank->rotate(angle);
    EXPECT_EQ(tank->getPosition(), angle);
}

TEST_F(Tanktest, fire)
{
    int amount_before = tank->get_weapon().get_bullets().size();
    tank->fire();
    int amount_after = tank->get_weapon().get_bullets().size();
    EXPECT_EQ(amount_before, amount_after + 1 );
}

#endif // TANK_TEST_H
