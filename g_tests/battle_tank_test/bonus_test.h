#ifndef BONUS_TEST_H
#define BONUS_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank/bonus.h"


class BonusTest : public ::testing::Test {
protected:
    void SetUp()
    {
        bonus = new Bonus(BONUS_TYPE_DAMAGE, BONUS_DEFAULT_COEFFICIENT);
    }

    void TearDown()
    {
        delete bonus;
    }
    Bonus *bonus;
};

TEST_F(BonusTest, constructorBonus)
{
    Bonus test = Bonus(BONUS_TYPE_DAMAGE, BONUS_DEFAULT_COEFFICIENT);
    EXPECT_EQ(*bonus, test);
};

TEST_F(BonusTest, setType)
{
    int type = BONUS_TYPE_HEALTH;
    bonus->set_type(type);
    EXPECT_EQ(bonus->get_type(), type);
};

TEST_F(BonusTest, setCoefficient)
{
    double coefficient = 1.5;
    bonus->set_coefficient(coefficient);
    EXPECT_EQ(bonus->get_coefficient(), coefficient);
};

#endif // BONUS_TEST_H
