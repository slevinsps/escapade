//#include <QtCore/QCoreApplication>
//#include <QtGui/QImage>
#include <iostream>
#include "cocos2d.h"

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class Position
{
public:
    Position(int x = 0, int y = 0);
    ~Position();

    bool operator == (const Position &other) const;

    bool operator != (const Position &other) const;

    int get_x() const;
    void set_x(int x);

    int get_y() const;
	void set_y(int y);

	cocos2d::Vec2 toVec2();
	Position(cocos2d::Vec2 v);

private:
    int x_, y_;
};

class SceneObject
{
public:
	Position position_;

	cocos2d::Sprite* sprite;

    SceneObject(Position position = Position(),
                std::string texture = "default.png");

	bool has_sprite() const;
};

#endif // SCENEOBJECT_H
