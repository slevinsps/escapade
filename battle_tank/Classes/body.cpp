#include "body.h"

Body::Body(Position position,
	int max_health,
	float rotation_speed,
	float speed,
	float speed_back,
	float current_rotation_angle,
	std::string name,
	std::string texture) :
	UnitComponent(position, texture, name, true),
	health_(max_health),
	max_health_(max_health),
	rotation_(rotation_speed, current_rotation_angle),
	forward_(speed, speed_back) {
	bar_ = new ComponentProgressBar(position, max_health, "health");
}

Body::~Body() {
	;
}

int Body::get_health() const {
	return health_;
}
int Body::get_max_health() const {
	return max_health_;
}

void Body::decrement_helth(int decr) {
	health_ -= decr;
}

void Body::increment_helth(int incr) {
	health_ += incr;
}

RotateMovement& Body::get_rotation_movement() {
	return rotation_;
}

void Body::set_rotation_movement(RotateMovement rm) {
	rotation_ = rm;
}

ForwardMovement& Body::get_forward_movement() {
	return forward_;
}

void Body::set_forward_movement(ForwardMovement fw) {
	forward_ = fw;
}

void Body::set_speed(int speed) {
	forward_.setSpeed(speed);
}


void Body::set_angle(float angle) {
	this->rotation_.rotate(angle);
}

float Body::get_angle() {
	return this->rotation_.get_current_angle();
}


void Body::set_max_speed(int speed) {
	forward_.setMaxSpeed(speed);
}

void Body::set_max_backspeed(int speed) {
	forward_.setMaxBackSpeed(speed);
}

Body Body::getLightBody(Position pos) {
	return Body(pos, 100, 2,
		2, 1, 0, "light body", // 60, 40, 0, "light body"
		"tank_light_body");
}

Body Body::getHeavyBody(Position pos) {
	return Body(pos, 300, 1,
		1, 1, 0, "heavy body", // 20, 10, 0, "heavy body"
		"tank_heavy_body");
}
