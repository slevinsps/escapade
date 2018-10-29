#include "unit.h"

Unit::Unit(int team_id,
           std::string name,
           Position position,
           QImage texture) : SceneObject(position, texture),
    team_id_(team_id),
            name_(name){};

bool Unit::is_friend(const Unit& unit) const {
    return unit.get_team_id() == get_team_id();
}

int Unit::get_team_id() const {
    return team_id_;
}

std::string Unit::get_name() const {
    return name_;
}

void Unit::set_team_id(int team_id) {
    team_id_ = team_id;
}

Player Unit::get_player() const {
    return player_;
}

Unit::~Unit(){};

bool Unit::operator == (const Unit &other) const
{
    return this->getPosition() == other.getPosition() &&
            this->get_name() == other.get_name() &&
            this->get_player() == other.get_player();
}

bool Unit::operator != (const Unit &other) const
{
    return this->getPosition() != other.getPosition() ||
            this->get_name() != other.get_name() ||
            this->get_player() != other.get_player();
}
