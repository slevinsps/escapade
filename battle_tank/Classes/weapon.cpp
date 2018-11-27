#include "weapon.h"

Weapon::Weapon(Position position,
	int damage,
	int recharge_one,
	int recharge_all,
	float angle,
	int amount_bullets,
	float rotation_speed,
    std::string name,
    std::string texture) :
	UnitComponent(position, texture, name, false),
    damage_(damage), recharge_one_(recharge_one),
	recharge_all_(recharge_all),
    cur_amount_bullets_(amount_bullets),
    max_amount_bullets_(amount_bullets),
    rotation_(rotation_speed, angle)
{
	last_time_shooted = get_time() - recharge_one_;
    for(int i = 0; i < max_amount_bullets_; ++i) {
        Bullet bullet(position);
        bullets_.push_back(bullet);
    }
		
}

int Weapon::get_recharge_one() const {
	return recharge_one_;
}
int Weapon::get_recharge_all() const {
	return recharge_all_;
}
int Weapon::get_damage() const {
	return damage_;
}
int Weapon::get_max_amount_bullets() const {
	return max_amount_bullets_;
}
int Weapon::get_cur_amount_bullets() const {
	return cur_amount_bullets_;
}

Bullet& Weapon::get_bullet_at(int i) {
	return bullets_[i];
}
std::vector<Bullet>& Weapon::get_bullets() {
	return bullets_;
}

void Weapon::recharge_bullets() {
	cur_amount_bullets_ = max_amount_bullets_;
}

void Weapon::apply_damage_bonus(Bonus bonus){}

void Weapon::fire(){
	int time_now = get_time();
	CCLOG("NOOO %d %d", time_now, cur_amount_bullets_);
	if (cur_amount_bullets_ > 0) {
		CCLOG("HMMMM %d %d", time_now, last_time_shooted);
		if (time_now- last_time_shooted > recharge_one_) {
			CCLOG("BEGIN %d %d", last_time_shooted, cur_amount_bullets_);
			int index = --cur_amount_bullets_;
			bullets_[index].sprite->setRotation(this->sprite->getRotation());
			bullets_[index].sprite->setPosition(this->sprite->getPosition());
			bullets_[index].move();
			last_time_shooted = time_now;
		}
	}
	else {
		if (time_now - last_time_shooted > recharge_all_) {
			recharge_bullets();
		}
	}
};

float Weapon::get_angle_speed() const{
	return rotation_.get_speed();
}

float Weapon::get_angle() const {
	return rotation_.get_current_angle();
}
void Weapon::set_angle(float angle) {
	rotation_.set_current_angle(angle);
}

Weapon Weapon::getLightWeapon(Position pos) {
	return Weapon(pos, 10, 1, 1, 0, 20,
		2, "light weapon",
		"tank_light_weapon");
}

Weapon Weapon::getHeavyWeapon(Position pos) {
	return Weapon(pos, 40, 2, 10, 0, 4,
		1 , "hard weapon",
		"tank_heavy_weapon");
}