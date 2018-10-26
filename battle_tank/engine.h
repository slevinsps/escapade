#ifndef ENGINE_H
#define ENGINE_H

#include "component.h"

#define ENGINE_SPEED 100
#define ENGINE_BACKSPEED 20

class Engine : public Component
{
public:
    Engine(Position _position = Position(),
           QImage _texture = QImage("weapon.png"),
           int _speed = ENGINE_SPEED,
           int _backspeed = ENGINE_BACKSPEED) :
        Component(_position, _texture),
        speed(_speed), backspeed(_backspeed){}
protected:
    int speed;
    int backspeed;
};

#endif // ENGINE_H
