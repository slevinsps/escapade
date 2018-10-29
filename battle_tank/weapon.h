#ifndef WEAPON_H
#define WEAPON_H

#include "bullet.h"
#include "component.h"
#include "rotational_movement.h"
#include <vector>

#define WEAPON_DEFAULT_DAMAGE 10
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
    Weapon(Position position = Position(),
           int damage = WEAPON_DEFAULT_DAMAGE,
           int recharge = WEAPON_DEFAULT_RECHANGE,
           int angle = 0,
           int amount_bullets = WEAPON_AMOUNT_BULLETS,
           int rotation_speed = WEAPON_ROTATION_SPEED,
           std::string name = "default weapon",
           QImage texture = QImage("weapon.png")) :
            Component(position, texture, name),
            damage_(damage), recharge_(recharge),
            cur_amount_bullets_(amount_bullets),
            max_amount_bullets_(amount_bullets),
            rotation_(rotation_speed, angle){
            for(int i = 0; i < max_amount_bullets_; ++i) {
                Bullet bullet(position);
                bullets_.push_back(bullet);
            }
    }

    int fire();
    void apply_damage_bonus(Bonus bonus);
    int get_damage();
    int incr_damage(int);
    int decr_damage(int);

    int get_recharge();
    int get_max_amount_bullets();
    int get_cur_amount_bullets();

    int recharge_bullets();
    Bullet& get_bullet_at(int i);
    std::vector<Bullet>& get_bullets();

    RotateMovement& get_rotation_movement();
    void set_get_rotation_movement(RotateMovement);

private:
    int damage_;
    int recharge_;
    int cur_amount_bullets_;
    int max_amount_bullets_;
    std::vector<Bullet> bullets_;
    RotateMovement rotation_;
};

#endif // WEAPON_H
