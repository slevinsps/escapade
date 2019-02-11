#ifndef PLAYER_H
#define PLAYER_H

#include "user.h"
#include "TankTeam.h"

class Player: public User, public FightingUnits
{
public:
	Player(User user, int team_id, int life = 1);

	int get_life() const;

	// Если подобран бонус
	void increase_life();

	// Если начался новый раунд
	void new_match();

	void increase_deaths();

	void change_team_id(int id);

	int get_team_id() const;
private:
	int life_;
	TankTeam team_;
};

#endif // PLAYER_H
