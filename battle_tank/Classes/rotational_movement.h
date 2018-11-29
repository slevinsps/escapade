#ifndef ROTATE_MOVEMENT_H
#define ROTATE_MOVEMENT_H

#include <thread>
#include <Windows.h>

#include "movement.h"

class RotateMovement : public Movement
{
public:
	RotateMovement(float speed, float current_angle);
	~RotateMovement();

	float get_current_angle() const;
    void set_current_angle(int angle);

	void angle_zero();

	float get_speed() const;

    bool operator == (const RotateMovement &other);
private:
    float current_angle_;
	float speed_;

	void angle_to_zero();
};

#endif // ROTATE_MOVEMENT_H

