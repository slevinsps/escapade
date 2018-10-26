#ifndef BODY_H
#define BODY_H

#include "component.h"

#define BODY_HEALTH 300
#define BODY_ROTATION_SPEED 20


class Body : public Component
{
public:
    Body(Position _position = Position(),
         QImage _texture = QImage("body.png"),
         int _health = BODY_HEALTH,
         int _rotation_speed = BODY_ROTATION_SPEED,
         int _current_rotation_angle = 0) :
        Component(_position, _texture),
        health(_health), rotation_speed(_rotation_speed),
        current_rotation_angle(_current_rotation_angle){}
protected:
    int health;
    int rotation_speed;
    int current_rotation_angle;
};

#endif // BODY_H
