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
    Component(Position position, QImage texture,
              std::string name);
protected:
    std::string name_;

    virtual void applyBonus(Bonus bonus);
};

#endif // COMPONENT_H
