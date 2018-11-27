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

class Weapon: public UnitComponent
{
public:
    // Ожидается позиция юнита, поэтому она задается явно
    // Дальше идут необязательные параметры конкретной модели
    // Поскольку не планируется изменение картинки, она
    // стоит в конце
    Weapon(Position position = Position(),
		float damage = WEAPON_DEFAULT_DAMAGE,
		float recharge = WEAPON_DEFAULT_RECHANGE,
		float angle = 0,
		float amount_bullets = WEAPON_AMOUNT_BULLETS,
		float rotation_speed = WEAPON_ROTATION_SPEED,
        std::string name = "default weapon",
        std::string texture = "tank_light_weapon");

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

	float get_angle_speed() const;

	float get_angle() const;
    void set_angle(float angle);

	// Получить экземпляры слабой и сильной пушек

	static Weapon getLightWeapon(Position pos = Position());

	static Weapon getHeavyWeapon(Position pos = Position());

private:
    int damage_;
    int recharge_;
    int cur_amount_bullets_;
    int max_amount_bullets_;
    std::vector<Bullet> bullets_;
    RotateMovement rotation_;
};

#endif // WEAPON_H
