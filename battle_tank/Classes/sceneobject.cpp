#include "sceneobject.h"

static void problemLoading(std::string filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool SceneObject::has_sprite() const {
	return sprite != nullptr;
}

SceneObject::SceneObject(Position position,
	std::string texture) {
	position_ = position;

	sprite = nullptr;
	sprite = cocos2d::Sprite::create(texture);
	if (sprite == nullptr) {
		problemLoading(texture);
		sprite = cocos2d::Sprite::create("error.png");
	} else {
		sprite->setPosition(position.toVec2());
	}
}

Position::Position(int x, int y) : x_(x), y_(y){}

Position::~Position(){}

cocos2d::Vec2 Position::toVec2() {
	return cocos2d::Vec2(x_, y_);
}

Position::Position(cocos2d::Vec2 v) {
	x_ = v.x;
	y_ = v.y;
}

int Position::get_x() const {
    return x_;
}
void Position::set_x(int x) {
    x_ = x;
}

int Position::get_y() const {
    return y_;
}

void Position::set_y(int y) {
    y_ = y;
}

bool Position::operator == (const Position &other) const
{
    return (this->get_x() == other.get_x());
}

bool Position::operator != (const Position &other) const
{
    return this->get_y() != other.get_y();
}
