//#include <QtCore/QCoreApplication>
//#include <QtGui/QImage>
#include <iostream>
#include "cocos2d.h"

#include "BodyParser.h"

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class Position
{
public:
    Position(float x = 0, float y = 0);
    ~Position();

    bool operator == (const Position &other) const;

    bool operator != (const Position &other) const;

	Position& operator=(const Position& t) {
		this->x_ = t.get_x();
		this->y_ = t.get_y();
		return *this;
	}

	float get_x() const;
    void set_x(float x);

	float get_y() const;
	void set_y(float y);

	cocos2d::Vec2 toVec2();
	Position(cocos2d::Vec2 v);

private:
    float x_, y_;
};

class SceneObject
{
public:
	Position position_;

	cocos2d::Sprite* sprite;

	SceneObject(Position position = Position(),
		std::string filename = "error",
		bool physic = false);

	bool has_sprite() const;
};

#endif // SCENEOBJECT_H
