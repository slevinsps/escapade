#ifndef ROTATE_MOVEMENT_H
#define ROTATE_MOVEMENT_H

#include <thread>
#include <mutex>
#include "cocos2d.h"

#include "movement.h"

class RotateMovement : public Movement
{
public:
	RotateMovement(float speed, float current_angle);
	~RotateMovement();

	RotateMovement(const RotateMovement& t) {
		this->speed_ = t.speed_;
		this->current_angle_ = t.current_angle_;
	}

	RotateMovement& operator=(const RotateMovement& t) {
		this->speed_ = t.speed_;
		this->current_angle_ = t.current_angle_;
		return *this;
	}

	float get_current_angle() const;
    void set_current_angle(float angle);

	void angle_zero();

	void rotate(float angle_param);

	float get_speed() const;

    bool operator == (const RotateMovement &other);
private:
	std::mutex g_lock;
    float current_angle_;
	float speed_;

	void angle_to_value(float angle_param);

	void angle_to_zero();
};

#endif // ROTATE_MOVEMENT_H

