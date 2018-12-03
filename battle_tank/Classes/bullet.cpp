#include "bullet.h"
Bullet::Bullet(
	Position pos, float range,
	float forward_speed,
	float rotation_speed,
	int pass,
	std::string texture) :
	SceneObject(pos, texture, true),
	forward_(forward_speed, forward_speed),
	rotation_(rotation_speed, sprite->getRotation()),
	pass_throught_units_times(pass),
	range_(range) {
	
}

int Bullet::move() {
	auto physic = sprite->getPhysicsBody();
	auto angle_ = Movement::get_angle(sprite->getRotation());

	float angle_radians = angle_ / 180.f * M_PI;

	float max_speed = forward_.getMaxSpeed();

	float ax = sinf(angle_radians);
	float ay = cosf(angle_radians);

	float length = powf(ax * ax + ay * ay, 0.5);

	float k = range_ / length;

	sprite->stopAllActions();
	sprite->setOpacity(255);
	sprite->setPosition(sprite->getPosition() + Vec2(ax, ay) * 20);

	auto flyBullet = MoveTo::create(range_ / forward_.getMaxSpeed(), sprite->getPosition() + Vec2(ax, ay)*k);
	auto missing = FadeOut::create(0.8f);

	sprite->runAction(Sequence::create(flyBullet->clone(), missing->clone(), nullptr));

	return 0;
}

int Bullet::get_range() const {
	return range_;
}
int Bullet::get_pass_throught() const {
	return pass_throught_units_times;
}

// Попадание в танк
void Bullet::hit() {
	pass_throught_units_times--;
}

// Продолжать движение? 
bool Bullet::continue_moving() {
	return pass_throught_units_times > 0;
}