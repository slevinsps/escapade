#include "weapon.h"

Weapon::Weapon(Position position,
	int damage,
	milliseconds recharge_one,
	milliseconds recharge_all,
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
	bar_ = new ComponentProgressBar(position, amount_bullets, "recharge");
	last_time_shooted = high_resolution_clock::now() - recharge_one_;
    for(int i = 0; i < max_amount_bullets_; ++i) {
        Bullet bullet(position);
        bullets_.push_back(bullet);
    }
		
}

Weapon::~Weapon() {
	;
}

milliseconds Weapon::get_recharge_one() const {
	return recharge_one_;
}
milliseconds Weapon::get_recharge_all() const {
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
	bar_->set_current(max_amount_bullets_);
}

void Weapon::apply_damage_bonus(Bonus bonus){}

void Weapon::fire(){
	steady_clock::time_point time_now = steady_clock::now();
	if (cur_amount_bullets_ > 0) {
		if (time_now - last_time_shooted > recharge_one_) {
			int index = --cur_amount_bullets_;
			bullets_[index].sprite->setRotation(this->sprite->getRotation());
			bullets_[index].sprite->setPosition(this->sprite->getPosition());
			bullets_[index].move();

			bar_->set_current(cur_amount_bullets_);
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
	return Weapon(pos, 10, 40ms, 300ms, 0, 50,
		2, "light weapon",
		"tank_light_weapon");
}

Weapon Weapon::getHeavyWeapon(Position pos) {
	return Weapon(pos, 40, 1000ms, 2000ms, 0, 4,
		1 , "hard weapon",
		"tank_heavy_weapon");
}