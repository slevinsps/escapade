#ifndef SCENE_TEST_H
#define SCENE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank3/battleground.h"
#include "../../battle_tank3/unit_control.h"
#include "../../battle_tank3/user.h"

class SceneTest : public ::testing::Test {
protected:
    void SetUp()
    {
        std::vector<Unit> units;
        Map map;
        bonusControl bonuses;
        scene = new Scene(units, map, bonuses);
    }

    void TearDown()
    {
        delete scene;
    }
    Scene *scene;
};

TEST_F(SceneTest, constructorScene)
{
    std::vector<Unit> units;
    Map map;
    bonusControl bonuses;
    Scene sce(units, map, bonuses);
    EXPECT_EQ(*scene, sce);
};

TEST_F(SceneTest, setUnits)
{
    std::vector<Unit> units;
    scene->setUnits(units);

    EXPECT_EQ(units, scene->getUnits());
};

TEST_F(SceneTest, setMap)
{
    Map map;
    scene->setMap(map);

    EXPECT_EQ(map, scene->getMap());
};

TEST_F(SceneTest, setBonuses)
{
    bonusControl bs;
    scene->setBonusControl(bs);

    EXPECT_EQ(bs, scene->getBonusControl());
};

#endif // SCENE_TEST_H
