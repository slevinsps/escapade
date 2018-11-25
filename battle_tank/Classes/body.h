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
	Body(Position position = Position(),
		int max_health = BODY_MAX_HEALTH,
		int rotation_speed = BODY_DEFAULT_ROTATION_SPEED,
		int speed = BODY_DEFAULT_ROTATION_SPEED,
		int speed_back = BODY_DEFAULT_ROTATION_SPEED,
		int current_rotation_angle = BODY_DEFAULT_ANGLE,
		std::string name = "default body",
		std::string texture = "tank_light_body.png");

    void apply_health_bonus(Bonus& bonus);
    void apply_speed_bonus(Bonus& bonus);
    void decrement_helth(int decr);
    void increment_helth(int incr);
    int get_health() const;
    int get_max_health() const;

    RotateMovement get_rotation_movement() const;
    void set_rotation_movement(RotateMovement);

    ForwardMovement get_forward_movement() const;
    void set_forward_movement(ForwardMovement);

protected:
    int max_health_;
    int health_;
    RotateMovement rotation_;
    ForwardMovement forward_;
};

#endif // BODY_H