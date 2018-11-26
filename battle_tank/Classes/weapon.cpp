#include "weapon.h"

Weapon::Weapon(Position position,
       int damage,
       int recharge,
       int angle,
       int amount_bullets,
       int rotation_speed,
       std::string name,
       std::string texture) :
    Component(position, texture, name),
    damage_(damage), recharge_(recharge),
    cur_amount_bullets_(amount_bullets),
    max_amount_bullets_(amount_bullets),
    rotation_(rotation_speed, angle)
{
	// Вызывает краш программы, временно закоменчено
	/*
        for(int i = 0; i < max_amount_bullets_; ++i) {
            Bullet bullet(position);
            bullets_.push_back(bullet);
        }
		*/
}

void Weapon::apply_damage_bonus(Bonus bonus){}

int Weapon::fire(){
    return 0;
};
