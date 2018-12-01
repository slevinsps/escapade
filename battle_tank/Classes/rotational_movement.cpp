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

void RotateMovement::angle_to_zero() {
	float decr = get_speed();
	float eps = 0.00001;
	int mul = 1;

	float angle = get_angle(get_current_angle());

	if (angle < 0) {
		angle *= -1;
		mul *= -1;
	}

	while (angle > eps) {
		if (angle - decr < eps) {
			angle = 0;
		}
		else {
			angle -= decr;
		}
		set_current_angle(mul * angle);
		Sleep(10);
	}
}

void RotateMovement::angle_zero(){
	std::thread thread(&RotateMovement::angle_to_zero, this);
	thread.detach();
}

void RotateMovement::set_current_angle(int angle) {
    current_angle_ = angle;
}
bool RotateMovement::operator == (const RotateMovement &other) {
    return (get_current_angle() == other.get_current_angle() &&
		get_speed() == other.get_speed());
}
