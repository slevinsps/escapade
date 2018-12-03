#include "FightingUnits.h"



FightingUnits::FightingUnits()
{
	kills_ = 0;
	deaths_ = 0;
	damage_done_ = 0;
	damage_received_ = 0;
}


FightingUnits::~FightingUnits()
{
}

int FightingUnits::get_kills() const {
	return kills_;
}

void FightingUnits::increase_kills() {
	kills_++;
}

int FightingUnits::get_deaths() const {
	return deaths_;
}

void FightingUnits::increase_deaths() {
	deaths_++;
}

// Нанесение урона танком
void FightingUnits::increase_damage_done(int damage) {
	damage_done_ += damage;
}
// Получение урона
void FightingUnits::increase_damage_received(int damage) {
	damage_received_ += damage;
}

// Нанесение урона танком
int  FightingUnits::get_damage_done() const {
	return damage_done_;
}
// Получение урона
int FightingUnits::get_damage_received() const {
	return damage_received_;
}
