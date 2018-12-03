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

void RotateMovement::angle_to_value(float angle_param) {
	if (g_lock.try_lock() == true) {
		CCLOG("Block\n");
		float decr = get_speed();
		int mul = 1;

		float angle = get_angle(get_current_angle());
		float angle_target = angle + angle_param;
		int znak = 1;
		if (angle < angle_target) {
			decr *= -1;
			znak *= -1;
		}

		while ((angle - angle_target) * znak > 0) {
			if ((angle - decr - angle_target) * znak < 0) {
				angle = angle_target;
				break;
			}
			else {
				angle -= decr;
			}
			set_current_angle(angle);
			Sleep(10);
		}

		g_lock.unlock();
	}
	else
		CCLOG("Not Block\n");

}


void RotateMovement::rotate(float angle_param) {
	std::thread thread(&RotateMovement::angle_to_value, this, angle_param);
	thread.join();
}

void RotateMovement::set_current_angle(float angle) {
    current_angle_ = angle;
}
bool RotateMovement::operator == (const RotateMovement &other) {
    return (get_current_angle() == other.get_current_angle() &&
		get_speed() == other.get_speed());
}
