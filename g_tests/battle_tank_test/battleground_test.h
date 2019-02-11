#ifndef BATTLEGROUND_TEST_H
#define BATTLEGROUND_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank/battleground.h"

class BattleGroundTest : public ::testing::Test {
protected:
    void SetUp()
    {
        User user;
        UnitControl uc;
        UserControlBundle usb(user, uc);
        std::vector<UserControlBundle> vec;
        Scene scene;
        Visualizer vis(scene);
        Room room = Room(100,200);
        user.set_IP(1000);
        room.add_user(user);
        int time = 100;
        battle = new BattleGround(time, scene, room, vec,vis);
    }

    void TearDown()
    {
        delete battle;
    }
    BattleGround *battle;
};

TEST_F(BattleGroundTest, constructorBattleGroundCheckWithSame)
{
    Room room = Room(100, 100);
    User user;
    user.set_IP(1000);
    room.add_user(user);
    EXPECT_EQ(battle->get_room(), room);
    int time = 100;
    EXPECT_EQ(battle->get_time(), time);
    UnitControl uc;
    UserControlBundle usb(user, uc);
    std::vector<UserControlBundle> vec;
    EXPECT_EQ(battle->get_control_bundle(), vec);
    Scene scene;
    Visualizer vis(scene);
    EXPECT_EQ(battle->get_vizualizer(), vis);
};

TEST_F(BattleGroundTest, constructorBattleGroundCheckWithAnother)
{
    Room room = Room(100, 100);
    User user;
    user.set_IP(2018);
    room.add_user(user);
    ASSERT_NE(battle->get_room(), room);
};

TEST_F(BattleGroundTest, setVizualizer)
{
    Scene scene;
    Visualizer vis(scene);
    battle->set_vizualizer(vis);
    EXPECT_EQ(battle->get_vizualizer(), vis);
};

TEST_F(BattleGroundTest, setControlBundle)
{
    User user;
    UnitControl uc;
    UserControlBundle usb(user, uc);
    std::vector<UserControlBundle> vec;
    battle->set_control_bundle(vec);
    EXPECT_EQ(battle->get_control_bundle(), vec);
};

TEST_F(BattleGroundTest, setRoom)
{
    Room room = Room(100, 100);
    User user;
    user.set_IP(2018);
    room.add_user(user);
    battle->set_room(room);
    EXPECT_EQ(battle->get_room(), room);
};

TEST_F(BattleGroundTest, runBattle)
{
    EXPECT_EQ(battle->run_battle(), 0);
};

TEST_F(BattleGroundTest, stopBattle)
{
    EXPECT_EQ(battle->stop_battle(), 0);
};

#endif // BATTLEGROUND_TEST_H
