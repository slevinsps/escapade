#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank/player.h"

class PlayerTest : public ::testing::Test {
protected:
    void SetUp()
    {
        player = new Player(100, 100);
    }

    void TearDown()
    {
        delete player;
    }
    Player *player;
};

TEST_F(PlayerTest, constructor)
{
    Player tester0(100, 15);
    EXPECT_EQ(tester0.get_kills(), 100);
    EXPECT_EQ(tester0.get_deaths(), 15);

   Player tester;
   EXPECT_EQ(tester.get_kills(), 0);
   EXPECT_EQ(tester.get_deaths(), 0);

   Player tester2(10, 2);
   EXPECT_EQ(tester2.get_kills(), 10);
   EXPECT_EQ(tester2.get_deaths(), 2);

};

TEST_F(PlayerTest, increaseKills)
{
  int kills = player->get_kills();
  player->increase_kills();
  EXPECT_EQ(kills + 1, player->get_kills());
};

TEST_F(PlayerTest, increaseDeaths)
{
  int deaths = player->get_deaths();
  player->increase_deaths();
  EXPECT_EQ(deaths + 1, player->get_deaths());
};


#endif // PLAYER_TEST_H
