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
protected:
	int kills_;
	int deaths_;
};

