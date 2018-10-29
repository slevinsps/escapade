#include "component.h"

Component::Component(Position _position, QImage _texture,
          std::string _name):
    SceneObject(_position, _texture), name(_name){}
