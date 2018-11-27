#ifndef ROTATE_MOVEMENT_H
#define ROTATE_MOVEMENT_H

#include "movement.h"

#define ROTATION_MOVEMENT_DEFAULT_SPEED 0
#define ROTATION_MOVEMENT_DEFAULT_ANGLE 0

class RotateMovement : public Movement
{
public:
	RotateMovement(float speed, float current_angle);
	~RotateMovement();

	float get_current_angle() const;
    void set_current_angle(int angle);

	float get_speed() const;

    bool operator == (const RotateMovement &other);
private:
    float current_angle_;
	float speed_;
};

#endif // ROTATE_MOVEMENT_H

