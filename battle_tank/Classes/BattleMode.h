#pragma once

#include <string>

enum types {
	ONE = 1,
	ONE_DEATHMATCH = 2,
	TEAM = 3,
	TEAM_DEATHMATCH = 4
};

// ����� �����
class BattleMode
{
public:
	BattleMode(int id = ONE);
	~BattleMode();

	static BattleMode one() {

	}
private:
	// �������� ������
	std::string name;
	// ���������� ������
	int life;
	// ���������� ������
	int team;
};

