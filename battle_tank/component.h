#ifndef COMPONENT_H
#define COMPONENT_H

#include "sceneobject.h"

class Component : public SceneObject
{
public:
    Component(Position _position, QImage _texture):
        SceneObject(_position, _texture){}
};

#endif // COMPONENT_H
