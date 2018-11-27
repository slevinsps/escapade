#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "sceneobject.h"
#include "player.h"

// Тип танка
enum types {
	LIGHT = 0,
	HARD = 1
};

// Тип выстрела
enum shot_types {
	ONE = 0,
	BURST = 1,
	ALL = 2
};

class Unit : public SceneObject
{
private:
    int team_id_;
    std::string name_;
	int type_;
    Player player_;

public:
	cocos2d::Label* unit_name;

    // Явное указание игрока и команды
	Unit(Player player, int _team_id = 0,
		std::string name = "unnamed unit",
		int type = LIGHT,
         Position _position = Position(),
         std::string texture = "red_circle.png");

    ~Unit();

    // Является ли юнит союзником
    bool is_friend(const Unit& unit) const;

    int get_team_id() const;

    std::string get_name() const;

    Player get_player() const;
    void set_player(Player player);

    bool operator == (const Unit &other) const;

    bool operator != (const Unit &other) const;

	void setName(std::string name);

	virtual void setModel(int type);

	// Устанавливает одинаковое положение(позицию и угол) для всех объектов юнита
	// В частности для корпуса: Корпус, Пушка, Ник, полоса здоровья, перезарядки и т.д.
	virtual void sinchronize() {};

	virtual void set_position(Position pos) {};

	void set_team_id(int id);

	// power - процент от максимальной скорости
	// back - флаг движения назад
	virtual void move(float power, bool back) {};

	// power - процент от максимальной скорости
	// clockwise - флаг движения по часовой
    virtual void rotate_body(float power, bool clockwise) {};

	// power - процент от максимальной скорости
	// clockwise - флаг движения по часовой
	virtual void rotate_weapon(float power, bool clockwise) {};

	// Тип выстрела - см. структуру shot_types
    virtual void fire(int shot) {};
};

#endif // UNIT_H
