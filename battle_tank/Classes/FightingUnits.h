#pragma once
class FightingUnits
{
public:
	FightingUnits();
	~FightingUnits();

	int get_kills() const;
	int get_deaths() const;

	// � ������ ���� ����� ���� ������� ������
	void increase_kills();

	// ���� ����� �����
	void increase_deaths();

	// ��������� ����� ������
	void increase_damage_done(int damage);
	// ��������� �����
	void increase_damage_received(int damage);

	// ��������� ����� ������
	int get_damage_done() const;
	// ��������� �����
	int get_damage_received() const;
protected:
	int kills_;
	int deaths_;

	int damage_done_;
	int damage_received_;
};

