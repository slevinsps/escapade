#include "body.h"

Body::Body(Position position,
	int max_health,
	int rotation_speed,
	int speed,
	int speed_back,
	int current_rotation_angle,
	std::string name,
	std::string texture) :
	Component(position, texture, name),
	health_(max_health),
	max_health_(max_health),
	rotation_(rotation_speed, current_rotation_angle),
	forward_(speed, speed_back) {}

int Body::get_health() const{
	return health_;
}
int Body::get_max_health() const{
	return max_health_;
}

void Body::decrement_helth(int decr) {
	health_ -= decr;
}

void Body::increment_helth(int incr) {
	health_ += incr;
}

RotateMovement Body::get_rotation_movement() const{
	return rotation_;
}

void Body::set_rotation_movement(RotateMovement rm) {
	rotation_ = rm;
}

ForwardMovement Body::get_forward_movement() const{
	return forward_;
}

void Body::set_forward_movement(ForwardMovement fw) {
	forward_ = fw;
}