#ifndef BODY_H
#define BODY_H

#include "component.h"
#include "rotational_movement.h"
#include "forward_movement.h"

#define BODY_MAX_HEALTH 300
#define BODY_DEFAULT_ROTATION_SPEED 203
#define BODY_DEFAULT_SPEED 20
#define BODY_DEFAULT_ANGLE 0

class Body : public UnitComponent
{
public:
	// Ожидается позиция юнита, поэтому она задается явно
	// Дальше идут необязательные параметры конкретной модели
	// Поскольку не планируется изменение картинки, она
	// стоит в конце
	Body(Position position = Position(),
		int max_health = BODY_MAX_HEALTH,
		float rotation_speed = BODY_DEFAULT_ROTATION_SPEED,
		float speed = BODY_DEFAULT_ROTATION_SPEED,
		float speed_back = BODY_DEFAULT_ROTATION_SPEED,
		float current_rotation_angle = BODY_DEFAULT_ANGLE,
		std::string name = "default body",
		std::string texture = "tank_light_body") ;

	~Body();

	Body& operator=(const Body& other) {
		this->name_ = other.name_;
		this->bar_ = other.bar_;
		this->max_health_ = other.max_health_;
		this->health_ = other.health_;

		this->rotation_ = other.rotation_;
		this->forward_ = other.forward_;
		return *this;
	}

    void apply_health_bonus(Bonus& bonus);
    void apply_speed_bonus(Bonus& bonus);
    void decrement_helth(int decr);
    void increment_helth(int incr);
    int get_health() const;
    int get_max_health() const;

	void set_angle(float angle);

	float get_angle() const;

    RotateMovement& get_rotation_movement();
    void set_rotation_movement(RotateMovement);

    ForwardMovement& get_forward_movement();
    void set_forward_movement(ForwardMovement);

	void set_speed(int speed);
	void set_max_speed(int speed);
	void set_max_backspeed(int speed);

	// Получить экземпляры быстрого и крепкого корпусов

	static Body getLightBody(Position pos = Position());

	static Body getHeavyBody(Position pos = Position());

protected:
    int max_health_;
    int health_;

    RotateMovement rotation_;
    ForwardMovement forward_;
};

#endif // BODY_H
