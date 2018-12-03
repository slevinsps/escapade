#pragma once
class FightingUnits
{
public:
	FightingUnits();
	~FightingUnits();

	int get_kills() const;
	int get_deaths() const;

	// В случае если игрок убил другого игрока
	void increase_kills();

	// Если игрок погиб
	void increase_deaths();
protected:
	int kills_;
	int deaths_;
};

