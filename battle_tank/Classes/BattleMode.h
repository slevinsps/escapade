#pragma once

#include <string>

enum types {
	ONE = 1,
	ONE_DEATHMATCH = 2,
	TEAM = 3,
	TEAM_DEATHMATCH = 4
};

// Режим битвы
class BattleMode
{
public:
	BattleMode(int id = ONE);
	~BattleMode();

	static BattleMode one() {

	}
private:
	// Название режима
	std::string name;
	// Количество жизней
	int life;
	// Количество команд
	int team;
};

