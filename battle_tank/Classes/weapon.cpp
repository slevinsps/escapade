#include "weapon.h"

Weapon::Weapon(Position position,
	float damage,
	float recharge,
	float angle,
	float amount_bullets,
	float rotation_speed,
    std::string name,
    std::string texture) :
	UnitComponent(position, texture, name, false),
    damage_(damage), recharge_(recharge),
    cur_amount_bullets_(amount_bullets),
    max_amount_bullets_(amount_bullets),
    rotation_(rotation_speed, angle)
{
	
    for(int i = 0; i < max_amount_bullets_; ++i) {
        Bullet bullet(position);
        bullets_.push_back(bullet);
    }
		
}

void Weapon::apply_damage_bonus(Bonus bonus){}

int Weapon::fire(){
    return 0;
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
	return Weapon(pos, 10, 2, 0, 20,
		2, "light weapon",
		"tank_light_weapon");
}

Weapon Weapon::getHeavyWeapon(Position pos) {
	return Weapon(pos, 40, 20, 0, 4,
		1 , "hard weapon",
		"tank_heavy_weapon");
}