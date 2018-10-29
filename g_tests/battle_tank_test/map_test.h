#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank3/battleground.h"
#include "../../battle_tank3/unit_control.h"

class MapTest : public ::testing::Test {
protected:
    void SetUp()
    {
        map = new Map("test_map.txt");
    }

    void TearDown()
    {
        delete map;
    }
    Map *map;
};

TEST_F(MapTest, constructorMap)
{
   Map m("test_map.txt");
   EXPECT_EQ(*map, m);
};

TEST_F(MapTest, setFilename)
{
   map->set_filename("test_map1.txt");
   Map m("test_map.txt");
   EXPECT_EQ(*map, m);
};

#endif // MAP_TEST_H
