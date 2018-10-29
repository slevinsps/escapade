#ifndef BONUSCONTROL_TEST_H
#define BONUSCONTROL_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank3/bonuscontrol.h"


class BonusControlTest : public ::testing::Test {
protected:
    void SetUp()
    {
        bcontrol = new bonusControl(10);
    }

    void TearDown()
    {
        delete bcontrol;
    }
    bonusControl *bcontrol;
};

TEST_F(BonusControlTest, constructorbonusControl)
{
    bonusControl *test = new bonusControl(10);
    EXPECT_EQ(*bcontrol, *test);
};

TEST_F(BonusControlTest, removeBonus)
{
     std::vector<Bonus> arr = bcontrol->get_bonuses() ;
     bcontrol->remove_bonus(0);

    EXPECT_EQ(arr.size() - 1, bcontrol->get_bonuses());
};

#endif // BONUSCONTROL_TEST_H
