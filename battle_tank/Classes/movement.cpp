#include "movement.h"
/*
Movement::Movement(int max_speed, int current_speed) :
max_speed_(max_speed), current_speed_(current_speed){}

Movement::~Movement(){}

int Movement::get_max_speed() const {
return max_speed_;
}

int Movement::get_current_speed() const {
return current_speed_;
}

void Movement::set_max_speed(int max_speed) {
max_speed_ = max_speed;
}

void Movement::set_current_speed(int current_speed) {
current_speed_ = current_speed;
}
*/
float Movement::get_angle(float ang_f) {
	int ang = (int)ang_f;
	if (ang < 0) {
		return -((-ang) % 360);
	}
	return ang % 360;

}
