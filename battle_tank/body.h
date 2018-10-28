#ifndef BODY_H
#define BODY_H

#include "component.h"
#include "rotationalmotion.h"

#define BODY_MAX_HEALTH 300
#define BODY_DEFAULT_ROTATION_SPEED 20
#define BODY_DEFAULT_ANGLE 0


class Body : public Component
{
public:
    // Ожидается позиция юнита, поэтому она задается явно
    // Дальше идут необязательные параметры конкретной модели
    // Поскольку не планируется изменение картинки, она
    // стоит в конце
    Body(Position _position,
         int _max_health = BODY_MAX_HEALTH,
         int _rotation_speed = BODY_DEFAULT_ROTATION_SPEED,
         int _current_rotation_angle = BODY_DEFAULT_ANGLE,
         std::string name = "default body",
         QImage _texture = QImage("body.png")) :
        Component(_position, _texture, name),
        health(_max_health), max_health(_max_health),
        rotation(_rotation_speed, _current_rotation_angle){}

    void applyBonus(Bonus bonus) override;
protected:
    int max_health;
    int health;
    RotationalMotion rotation;
    int rotation_speed;
    int current_rotation_angle;
};

#endif // BODY_H
