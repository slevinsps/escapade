#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

#include "sceneobject.h"
#include "bonus.h"

class Component : public SceneObject
{
public:
    // Component абстрактный класс, поэтому без дефолтных
    // значений
    Component(Position _position, QImage _texture,
              std::string _name):
        SceneObject(_position, _texture), name(_name){}
protected:
    std::string name;

    virtual void applyBonus(Bonus bonus);
};

#endif // COMPONENT_H
