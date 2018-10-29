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
              std::string _name);
    ~Component() = default;
protected:
    std::string name;

    virtual void applyBonus(Bonus bonus) = 0;
};

#endif // COMPONENT_H
