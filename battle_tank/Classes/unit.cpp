#include "unit.h"

Unit::Unit(std::string name,
	int type,
    Position position,
    std::string texture) :
		SceneObject(position, texture, false),
		name_(name),
		type_(type)
	{
	runnable = false;
	unit_name = cocos2d::Label::createWithTTF(
		name, "fonts/Marker Felt.ttf", 10);
	};

void Unit::launch() {
	runnable = true;
}

// Вызывается при уничтожении юнита, ставит runnable в false
void Unit::destroy() {
	runnable = false;
}

std::string Unit::get_name() const {
    return name_;
}

Unit::~Unit(){};

void Unit::setName(std::string name) {
	if (!runnable) {
		name_ = name;
		unit_name = cocos2d::Label::createWithTTF(
			name, "fonts/Marker Felt.ttf", 10);
	}
}

void Unit::setModel(int type) {
	if (!runnable) {
		type_ = type;
	}
}

bool Unit::operator == (const Unit &other) const
{
	return this->name_ == other.name_;
}

bool Unit::operator != (const Unit &other) const
{
    return this->name_ != other.name_;
}
