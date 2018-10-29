#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank3/battleground.h"
#include "../../battle_tank3/unit_control.h"


class UnitTestt : public ::testing::Test {
protected:
    void SetUp()
    {
        unit = new Unit(1, "unit name", Position(10, 20));
    }

    void TearDown()
    {
        delete unit;
    }
    Unit *unit;
};

TEST_F(UnitTestt, constructor)
{
   Unit *unit = new Unit(1, "unit name", Position(10, 20));

   EXPECT_EQ(unit->get_name(), "unit name");
   EXPECT_EQ(unit->get_team_id(), 1);
   EXPECT_EQ(unit->getPosition(), Position(10, 20));
};

TEST_F(UnitTestt, setPlayer)
{
  Player player;
  unit->set_player(player);
  EXPECT_EQ(player, unit->get_player());
};

#endif // UNIT_TEST_H
