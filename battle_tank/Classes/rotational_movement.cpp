#include "rotational_movement.h"

RotateMovement::RotateMovement(float speed, float current_angle) :
    current_angle_(current_angle),
	speed_(speed)
{}

RotateMovement::~RotateMovement(){}

float RotateMovement::get_current_angle() const {
    return current_angle_;
}

float RotateMovement::get_speed() const {
	return speed_;
}

void RotateMovement::set_current_angle(int angle) {
    current_angle_ = angle;
}
bool RotateMovement::operator == (const RotateMovement &other) {
    return (get_current_angle() == other.get_current_angle() &&
		get_speed() == other.get_speed());
}
