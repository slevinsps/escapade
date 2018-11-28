#include "unit.h"

Unit::Unit(Player player,
	int team_id,
    std::string name,
	int type,
    Position position,
    std::string texture) :
		SceneObject(position, texture, false),
		player_(player),
		team_id_(team_id),
		name_(name),
		type_(type)
	{

	unit_name = cocos2d::Label::createWithTTF(
		name, "fonts/Marker Felt.ttf", 10);
	};

bool Unit::is_friend(const Unit& unit) const {
    return unit.get_team_id() == get_team_id();
}

int Unit::get_team_id() const {
    return team_id_;
}

std::string Unit::get_name() const {
    return name_;
}

Player Unit::get_player() const {
    return player_;
}

void Unit::set_player(Player player) {
    player_ = player;
}

Unit::~Unit(){};

void Unit::setName(std::string name) {
	name_ = name;
	unit_name = cocos2d::Label::createWithTTF(
		name, "fonts/Marker Felt.ttf", 10);
}

void Unit::setModel(int type) {
	type_ = type;
}

void Unit::set_team_id(int id) {
	team_id_ = id;
}

bool Unit::operator == (const Unit &other) const
{
    return this->get_name() == other.get_name() &&
            this->get_player() == other.get_player();
}

bool Unit::operator != (const Unit &other) const
{
    return this->get_name() != other.get_name() ||
            this->get_player() != other.get_player();
}
