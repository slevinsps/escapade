#ifndef STATIC_ROOM_PARAMETERS_H
#define STATIC_ROOM_PARAMETERS_H

#include <gtest/gtest.h>
#include "../../battle_tank/static_room_parameters.h"
#include "../../battle_tank/tank.h"

class StatisticTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        stat = new StaticRoomParameters();
    }
    void TearDown()
    {
        delete stat;
    }
    StaticRoomParameters *stat;
};
int get_max_of_players() const;
   void set_max_of_players(int);

   int get_time_limit() const;
   void set_time_limit(int);

   int get_time_start() const;
   void set_time_start(int);

   int get_max_of_matches() const;
   void set_max_of_matches(int);

TEST_F(StatisticTest, setMaxOfPlayers)
{
    int max_amount = 100;
    stat->set_max_of_players(max_amount);

    EXPECT_EQ(stat->get_max_of_players(), max_amount);
}

TEST_F(StatisticTest, setTimeLimit)
{
    int time_limit = 1000;
    stat->set_time_limit(time_limit);

    EXPECT_EQ(stat->get_time_limit(), time_limit);
}

TEST_F(StatisticTest, setMaxOfMatches)
{
    int matches = 3;
    stat->set_max_of_matches(matches);

    EXPECT_EQ(stat->get_max_of_matches(), matches);
}

#endif // STATIC_ROOM_PARAMETERS_H
