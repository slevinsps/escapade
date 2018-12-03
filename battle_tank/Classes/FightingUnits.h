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

	// Нанесение урона танком
	void increase_damage_done(int damage);
	// Получение урона
	void increase_damage_received(int damage);

	// Нанесение урона танком
	int get_damage_done() const;
	// Получение урона
	int get_damage_received() const;
protected:
	int kills_;
	int deaths_;

	int damage_done_;
	int damage_received_;
};

