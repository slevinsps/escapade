#pragma once

#include "FightingUnits.h"

class TankTeam : public FightingUnits
{
public:
	TankTeam(int id);
	~TankTeam();

	int get_id() const;

	void set_id(int id) { id_ = id; }
private:
	int id_;
};

