#include "tank.h"

Tank::Tank(std::string name, int type,
	Position position,
	std::string texture) :
	Unit(name, type, 
		position, texture),
	weapon_(Weapon::getLightWeapon()) {
	
	setModel(type);
}

void Tank::setModel(int type) {
	if (is_runnable()) {
		return;
	}
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
	if (!is_runnable()) {
		return;
	}
	cocos2d::Vec2 vec = pos.toVec2();
	cocos2d::Vec2 vec2 = cocos2d::Vec2(vec.x, vec.y + 20);

	unit_name->setPosition(vec2);
	body_.sprite->setPosition(vec);
	weapon_.sprite->setPosition(vec);
	sprite->setPosition(vec);
}

#include <cmath>

void Tank::move(float distance, bool back, bool keyboard) {
if (!is_runnable()) {
		return;
	}
	/*distance = 1;
	//this->body_.sprite->stopAllActions();
	auto angle_ = this->body_.rotation_.get_current_angle();
	CCLOG("Your rotation %f", this->sprite->getRotation())

	float angle_radians = angle_ / 180.f * M_PI;
	float ax = sinf(angle_radians);
	float ay = cosf(angle_radians);

	float length = powf(ax * ax + ay * ay, 0.5);

	float k = distance / length;
	float max_speed = 20;
	if (back) {
		max_speed = body_.get_forward_movement().getMaxBackSpeed();
		ax *= -1;
		ay *= -1;
	}
	else {
		max_speed = body_.get_forward_movement().getMaxSpeed();
	}

	max_speed = 20;
	auto flyBullet = MoveTo::create(distance / max_speed, this->body_.sprite->getPosition() + Vec2(ax, ay)*k);
	//auto missing = FadeOut::create(0.8f);

	//sprite->stopAllActions();
	
	this->body_.sprite->runAction(flyBullet->clone());
	Sleep(10);
	g_move.unlock();*/
	float max_speed = 1;
	if (back) {
		max_speed = -body_.get_forward_movement().getMaxBackSpeed();
	}
	else {
		max_speed = body_.get_forward_movement().getMaxSpeed();
	}
	this->body_.get_forward_movement().move(distance, max_speed, this->body_.get_rotation_movement(), keyboard);
	sinchronize();
	/*if (!(power >= 0.f && power < 1.f)) {

		power = 1.f;
	}
	auto physic = body_.sprite->getPhysicsBody();
	auto angle_ = this->body_.rotation_.get_current_angle();

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

	physic->setVelocity(cocos2d::Vec2(ax, ay));
	body_.set_speed(powf(ax * ax + ay * ay, 0.5f));
	sinchronize();

	//weapon_.sprite->getPhysicsBody()->setVelocity(cocos2d::Vec2(ax, ay));*/
}

void Tank::rotate_body(float angle, bool keyboard) {
	sinchronize();
	//body_.get_forward_movement().set_stop(true);
	//this->body_.get_forward_movement().move(distance, max_speed, this->body_.get_rotation_movement().get_current_angle(), keyboard);


	
	body_.get_rotation_movement().rotate(angle, keyboard);
	
	sinchronize();
}

void Tank::rotate_weapon(float power, bool clockwise) {
	if (!is_runnable()) {
		return;
	}
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
  if (!is_runnable()) {
		return;
	}
	// Ñòàâèì ïóøêó â òî æå ìåñòî, ÷òî è êîðïóñ
	//body_.sprite->getPhysicsBody()->setAngularVelocity(0);

	auto pos = body_.get_forward_movement().get_pos();// prite->getPosition();
	
	float x = pos.get_x();
	float y = pos.get_y();
	//CCLOG("POSSSS %f   %f\n", x, y);

	body_.sprite->setPosition(pos.toVec2());
	weapon_.sprite->setPosition(pos.toVec2());
	sprite->setPosition(pos.toVec2());

	unit_name->setPosition(x, y + 15);
	body_.bar_->setPosition(x, y - 15);
	weapon_.bar_->setPosition(x, y - 17);

	// Ïîâîðîò ïóøêè èçìåíÿåòñÿ â ñîîòâåñòâèè ñ ïîâîðîòîì êîðïóñà +
	// â ïóøêå õðàíèòñÿ óãîë ïîâîðîòà îðóäèÿ
	body_.sprite->setRotation(body_.get_angle());
	weapon_.sprite->setRotation(body_.sprite->getRotation() + weapon_.get_angle());

	sprite->setRotation(sprite->getRotation() + 1);

}

void Tank::fire(int shot) {
  if (!is_runnable()) {
		return;
	}
	weapon_.fire();
}

void Tank::center_weapon() {
  if (!is_runnable()) {
		return;
	}
	weapon_.center();
}