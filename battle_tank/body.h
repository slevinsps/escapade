#ifndef BODY_H
#define BODY_H

#include "component.h"
#include "rotational_movement.h"
#include "forward_movement.h"

#define BODY_MAX_HEALTH 300
#define BODY_DEFAULT_ROTATION_SPEED 203
#define BODY_DEFAULT_SPEED 20
#define BODY_DEFAULT_ANGLE 0


class Body : public Component
{
public:
    // Ожидается позиция юнита, поэтому она задается явно
    // Дальше идут необязательные параметры конкретной модели
    // Поскольку не планируется изменение картинки, она
    // стоит в конце
    Body(Position position,
         int max_health = BODY_MAX_HEALTH,
         int rotation_speed = BODY_DEFAULT_ROTATION_SPEED,
         int speed = BODY_DEFAULT_ROTATION_SPEED,
         int speed_back = BODY_DEFAULT_ROTATION_SPEED,
         int current_rotation_angle = BODY_DEFAULT_ANGLE,
         std::string name = "default body",
         QImage texture = QImage("body.png")) :
        Component(position, texture, name),
        health_(max_health),
        max_health_(max_health),
        rotation_(rotation_speed, current_rotation_angle){}

    void apply_health_bonus(Bonus& bonus) override;
    void apply_speed_bonus(Bonus& bonus) override;
    void decrement_helth(int decr);
    void increment_helth(int incr);
    int get_health();
    int get_max_health();

    RotateMovement& get_rotation_movement();
    void set_rotation_movement(RotateMovement);

    ForwardMovement& get_forward_movement();
    void set_forward_movement(ForwardMovement);

protected:
    int max_health_;
    int health_;
    RotateMovement rotation_;
    ForwardMovement rotation_;
};

#endif // BODY_H
