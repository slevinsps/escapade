#ifndef WEAPON_H
#define WEAPON_H

#include "bullet.h"
#include "component.h"
#include "rotational_movement.h"
#include <vector>

#define WEAPON_DEFAULT_DAMAGE 10
#define WEAPON_DEFAULT_RECHANGE_ONE 1
#define WEAPON_DEFAULT_RECHANGE_ALL 10
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
		int damage = WEAPON_DEFAULT_DAMAGE,
		int recharge_one = WEAPON_DEFAULT_RECHANGE_ONE,
		int recharge_all = WEAPON_DEFAULT_RECHANGE_ALL,
		float angle = 0,
		int amount_bullets = WEAPON_AMOUNT_BULLETS,
		float rotation_speed = WEAPON_ROTATION_SPEED,
        std::string name = "default weapon",
        std::string texture = "tank_light_weapon");

    void apply_damage_bonus(Bonus bonus);
    
    int incr_damage(int);
    int decr_damage(int);

	int get_time() { 
		return static_cast<long int>(
			std::chrono::duration_cast<std::chrono::nanoseconds>(
				std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
	}

    int get_recharge_one() const;
	int get_recharge_all() const;
	int get_damage() const;
    int get_max_amount_bullets() const;
    int get_cur_amount_bullets() const;

    void recharge_bullets();
    Bullet& get_bullet_at(int i);
    std::vector<Bullet>& get_bullets();

	float get_angle_speed() const;

	float get_angle() const;
    void set_angle(float angle);

	void fire();

	// Получить экземпляры слабой и сильной пушек

	static Weapon getLightWeapon(Position pos = Position());

	static Weapon getHeavyWeapon(Position pos = Position());

private:
    int damage_;
	int recharge_one_;
	int recharge_all_;
    int cur_amount_bullets_;
    int max_amount_bullets_;
    std::vector<Bullet> bullets_;
    RotateMovement rotation_;

	int last_time_shooted;
};

#endif // WEAPON_H
