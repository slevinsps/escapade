#ifndef SCENEOBJECT_TEST_H
#define SCENEOBJECT_TEST_H
#include <gtest/gtest.h>
#include "../../battle_tank/sceneobject.h"

class SceneObjectTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        QImage texture = QImage("default.png");
        position = new Position();
        object = new SceneObject(position,texture);
    }
    void TearDown()
    {
        delete object;
        delete position;
    }
    Position* position;
    SceneObject* object;
};

TEST_F(SceneObjectTest, Create)
{
    EXPECT_TRUE(texture == object->getImage());
    EXPECT_TRUE(object->getPosition() == position);
}

#endif // SCENEOBJECT_TEST_H
