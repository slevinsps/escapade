#pragma once
class FightingUnits
{
public:
	FightingUnits();
	~FightingUnits();

	int get_kills() const;
	int get_deaths() const;

	// Â ñëó÷àå åñëè èãðîê óáèë äðóãîãî èãðîêà
	void increase_kills();

	// Åñëè èãðîê ïîãèá
	void increase_deaths();

	// Íàíåñåíèå óðîíà òàíêîì
	void increase_damage_done(int damage);
	// Ïîëó÷åíèå óðîíà
	void increase_damage_received(int damage);

	// Íàíåñåíèå óðîíà òàíêîì
	int get_damage_done() const;
	// Ïîëó÷åíèå óðîíà
	int get_damage_received() const;
protected:
	int kills_;
	int deaths_;

	int damage_done_;
	int damage_received_;
};

