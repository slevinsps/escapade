#include "weapon.h"

Weapon::Weapon(Position _position,
       int _damage,
       int _recharge,
       int _amount_bullets,
       int _rotation_speed,
       std::string name,
       QImage _texture) :
    Component(_position, _texture, name),
    damage(_damage), recharge(_recharge),
    amount_bullets(_amount_bullets),
    rotation(_rotation_speed)
{

}

void Weapon::applyBonus(Bonus bonus){}

void Weapon::fire(){};
