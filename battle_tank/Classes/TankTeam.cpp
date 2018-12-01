#include "TankTeam.h"



TankTeam::TankTeam(int id) {
	id_ = id;
}


TankTeam::~TankTeam()
{
}

int TankTeam::get_id() const {
	return id_;
}