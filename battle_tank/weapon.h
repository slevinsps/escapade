#ifndef WEAPON_H
#define WEAPON_H

#include "bullet.h"
#include "component.h"
#include "rotationalmotion.h"
#include <vector>

#define WEAPON_DEFAULT_DANAGE 10
#define WEAPON_DEFAULT_RECHANGE 10
#define WEAPON_AMOUNT_BULLETS 4
#define WEAPON_ROTATION_SPEED 20

class Weapon: public Component
{
public:
    // Ожидается позиция юнита, поэтому она задается явно
    // Дальше идут необязательные параметры конкретной модели
    // Поскольку не планируется изменение картинки, она
    // стоит в конце
    Weapon(Position _position,
           int _damage = WEAPON_DEFAULT_DANAGE,
           int _recharge = WEAPON_DEFAULT_RECHANGE,
           int _amount_bullets = WEAPON_AMOUNT_BULLETS,
           int _rotation_speed = WEAPON_ROTATION_SPEED,
           std::string name = "default weapon",
           QImage _texture = QImage("weapon.png")) :
        Component(_position, _texture, name),
        damage(_damage), recharge(_recharge),
        amount_bullets(_amount_bullets),
        rotation(_rotation_speed)
    {}

    void fire();

    void applyBonus(Bonus bonus) override;
private:
    int damage;
    int recharge;
    int amount_bullets;
    std::vector<Bullet> bullets;
    RotationalMotion rotation;
};

#endif // WEAPON_H
