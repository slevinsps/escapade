#include "component.h"

UnitComponent::UnitComponent(Position position,
	std::string texture,
    std::string name,
	bool physic): SpriteSceneObject(position, texture, texture, physic),
		name_(name)
{
  ;
}

void UnitComponent::applyBonus(Bonus bonus){

}