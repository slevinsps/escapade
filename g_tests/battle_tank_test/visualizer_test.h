#ifndef VISUALIZER_TEST_H
#define VISUALIZER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank3/battleground.h"
#include "../../battle_tank3/unit_control.h"

class VisualizerTest : public ::testing::Test {
protected:
    void SetUp()
    {
        Map map("test_map.txt");
        Scene scene;
        visualizer = new Visualizer(scene);
    }

    void TearDown()
    {
        delete visualizer;
    }
    Visualizer *visualizer;
};

TEST_F(VisualizerTest, constructorVisualizer)
{
    Map map("test_map.txt");
    Scene scene;
    Visualizer *test = new Visualizer(scene);
   EXPECT_EQ(*visualizer, *test);
};

TEST_F(VisualizerTest, updateScene)
{
   EXPECT_EQ(visualizer->update_scene(), 0);
};

#endif // VISUALIZER_TEST_H
