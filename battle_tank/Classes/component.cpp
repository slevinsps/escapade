#include "component.h"

UnitComponent::UnitComponent(Position position,
	std::string texture,
    std::string name,
	bool physic):
		SceneObject(position, texture, physic),
		name_(name)
{
	bar_ = nullptr;
}

void UnitComponent::applyBonus(Bonus bonus){

}