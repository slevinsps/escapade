#include "unit.h"

Unit::Unit(std::string name, int type, Position position,
           std::string texture_create, std::string texture_destroyed)
    : SpriteSceneObject(position, texture_create, texture_destroyed, false),
      
		name_(name),
		type_(type)
	{
  CCLOG("Unit see %s", texture_destroyed);
	runnable = false;
	};

void Unit::launch() {
	runnable = true;
}

// Âûçûâàåòñÿ ïðè óíè÷òîæåíèè þíèòà, ñòàâèò runnable â false
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
	}
}

void Unit::setModel(int type) {
	if (!runnable) {
		type_ = type;
	}
}
  
bool Unit::is_runnable() const {
	return runnable;
}

bool Unit::operator == (const Unit &other) const
{
	return this->name_ == other.name_;
}

bool Unit::operator != (const Unit &other) const
{
    return this->name_ != other.name_;
}
