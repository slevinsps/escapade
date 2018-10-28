#ifndef WEAPON_TESTS_H
#define WEAPON_TESTS_H
#include <gtest/gtest.h>
#include "../../battle_tank/weapon.h"
#include "../../battle_tank/rotational_movement.h"
#include "../../battle_tank/bonus.h"
#include "../../battle_tank/bullet.h"


class WeaponTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        Bonus bonus = Bonus(10,1);
        weapon = new Weapon();
    }
    void TearDown()
    {
        delete body;
    }
    Weapon* weapon;
    Bonus bonus;
};

TEST_F(WeaponTest, Create)
{
    std::vector<Bullet> bullets_;
    for(int i = 0; i < max_amount_bullets_; ++i) {
        Bullet bullet(Position());
        bullets_.push_back(bullet);
    }
    EXPECT_EQ(weapon->get_damage(), 10);
    EXPECT_EQ(weapon->get_recharge(), 10);
    EXPECT_EQ(weapon->get_cur_amount_bullets(), 4);
    EXPECT_EQ(weapon->get_max_amount_bullets(), 4);
    EXPECT_EQ(weapon->get_rotation_movement(), RotateMovement(20, 0));
    EXPECT_TRUE(bullets_ == weapon->get_bullets());
}

TEST_F(WeaponTest, DecrDamage)
{
    weapon->decr_damage(1);
    EXPECT_EQ(weapon->get_damage(), 9);
}

TEST_F(WeaponTest, DecrDamageOverflow)
{
    weapon->decr_damage(1000);
    EXPECT_EQ(weapon->get_damage(), 1);
}

TEST_F(WeaponTest, IncrDamage)
{
    weapon->incr_damage(5);
    EXPECT_EQ(weapon->get_damage(), 6);
}

TEST_F(WeaponTest, IncrDamageOverflow)
{
    weapon->incr_damage(1000);
    EXPECT_EQ(weapon->get_damage(), 30);
}

TEST_F(WeaponTest, ApplyDamageBonus)
{
    weapon->decr_damage(20);
    weapon->apply_damage_bonus(bonus);
    EXPECT_EQ(weapon->get_damage(), 20);
}

TEST_F(WeaponTest, ApplyDamageBonusOverflow)
{
    weapon->apply_damage_bonus(bonus);
    EXPECT_EQ(weapon->get_damage(), 30);
}

TEST_F(WeaponTest, GetBullet)
{
    Bullet bull_1(Position());
    Bullet bull_2 = weapon->get_bullet_at(0);
    EXPECT_TRUE(bull_1 == bull_2);
}

TEST_F(WeaponTest, Fire)
{
    int ret = weapon->fire();
    EXPECT_TRUE(ret == 0);
}


TEST_F(WeaponTest, RechargeBullets)
{
    weapon->recharge_bullets();
    std::vector<Bullet> bullets_;
    for(int i = 0; i < max_amount_bullets_; ++i) {
        Bullet bullet(Position());
        bullets_.push_back(bullet);
    }
    EXPECT_TRUE(bullets_ == weapon->get_bullets());
}

#endif // WEAPON_TESTS_H
