#include "component.h"

Component::Component(Position position, QImage texture,
          std::string name):
    SceneObject(position, texture), name_(name){}

void Component::applyBonus(Bonus bonus){

}
