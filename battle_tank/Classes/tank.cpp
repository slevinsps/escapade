#include "tank.h"

Tank::Tank(Player player,
	int team_id, std::string name, int type,
	Position position,
	std::string texture) :
	Unit(player, team_id, name, type, 
		position, texture) {
	setModel(type);
}

void Tank::setModel(int type) {
	
	if (type == LIGHT) {
		weapon_ = Weapon::getLightWeapon(position_);
		body_ = Body::getLightBody(position_);
	}
	else {
		weapon_ = Weapon::getHeavyWeapon(position_);
		body_ = Body::getHeavyBody(position_);
	}
}

Weapon& Tank::get_weapon() {
	return weapon_;
}
Body& Tank::get_body() {
	return body_;
}

#include "cocos2d.h"
void Tank::set_position(Position pos) {
	cocos2d::Vec2 vec = pos.toVec2();
	cocos2d::Vec2 vec2 = cocos2d::Vec2(vec.x, vec.y + 15);

	unit_name->setPosition(vec2);
	body_.sprite->setPosition(vec);
	weapon_.sprite->setPosition(vec);

	weapon_.position_ = position_;
	body_.position_ = position_;
}

#include <cmath>

void Tank::move(float power, bool back) {
	if (!(power >= 0.f && power < 1.f)) {
		power = 1.f;
	}
	auto physic = body_.sprite->getPhysicsBody();
	auto angle_ = Movement::get_angle(physic->getRotation());

	float angle_radians = angle_ / 180.f * M_PI;

	float max_speed = 1;
	if (back) {
		max_speed = -body_.get_forward_movement().getMaxBackSpeed();
	}
	else {
		max_speed = body_.get_forward_movement().getMaxSpeed();
	}

	float start_speed = max_speed * power;

	float ax = start_speed * sinf(angle_radians);
	float ay = start_speed * cosf(angle_radians);

	CCLOG("results: %f %f, start_speed %f %f, angle_radians %f", ax, ay, max_speed, start_speed, angle_radians);

	physic->setVelocity(cocos2d::Vec2(ax, ay));
	body_.set_speed(powf(ax * ax + ay * ay, 0.5f));

	//weapon_.sprite->getPhysicsBody()->setVelocity(cocos2d::Vec2(ax, ay));
}

void Tank::rotate_body(float power, bool clockwise) {
	float body_angle = body_.sprite->getRotation();

	float anle_add = body_.get_rotation_movement().get_speed() * power;
	if (clockwise) {
		body_angle += anle_add;
	}
	else {
		body_angle -= anle_add;
	}

	body_.sprite->setRotation(body_angle);
}

void Tank::rotate_weapon(float power, bool clockwise) {
	float weapon_angle = weapon_.get_angle();

	float anle_add = weapon_.get_angle_speed() * power;
	if (clockwise) {
		weapon_angle += anle_add;
	}
	else {
		weapon_angle -= anle_add;
	}

	weapon_.set_angle(weapon_angle);
}

void Tank::sinchronize() {

	// Ставим пушку в то же место, что и корпус
	body_.sprite->getPhysicsBody()->setAngularVelocity(0);
	body_.sprite->getPhysicsBody()->resetForces();
	
	auto pos = body_.sprite->getPosition();
	float x = pos.x;
	float y = pos.y;

	weapon_.sprite->setPosition(pos);
	unit_name->setPosition(x, y + 15);
	// Поворот пушки изменяется в соотвествии с поворотом корпуса +
	// в пушке хранится угол поворота орудия
	weapon_.sprite->setRotation(body_.sprite->getRotation() + weapon_.get_angle());
}