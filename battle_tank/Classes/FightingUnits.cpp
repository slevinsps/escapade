#include "FightingUnits.h"



FightingUnits::FightingUnits()
{
	kills_ = 0;
	deaths_ = 0;
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
