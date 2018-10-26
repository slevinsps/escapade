#ifndef WEAPON_H
#define WEAPON_H

#include "bullet.h"
#include "component.h"
#include <vector>

#define WEAPON_DEFAULT_DANAGE 10
#define WEAPON_DEFAULT_RECHANGE 10
#define WEAPON_AMOUNT_BULLETS 4
#define WEAPON_ROTATION_SPEED 20

class Weapon: public Component
{
public:
    Weapon(Position _position = Position(),
           QImage _texture = QImage("weapon.png"),
           int _damage = WEAPON_DEFAULT_DANAGE,
           int _recharge = WEAPON_DEFAULT_RECHANGE,
           int _amount_bullets = WEAPON_AMOUNT_BULLETS,
           int _rotation_speed = WEAPON_ROTATION_SPEED) :
        Component(_position, _texture),
        damage(_damage), recharge(_recharge),
        amount_bullets(_amount_bullets),
        rotation_speed(_rotation_speed),
        current_rotation_angle(0)
    {}

    void fire();
protected:
    int damage;
    int recharge;
    int amount_bullets;
    std::vector<Bullet> bullets;
    int rotation_speed;
    int current_rotation_angle;
};

#endif // WEAPON_H
