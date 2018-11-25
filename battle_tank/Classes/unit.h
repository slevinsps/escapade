#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "sceneobject.h"
#include "player.h"

enum types {
	LIGHT = 0,
	HARD = 1
};

class Unit : public SceneObject
{
private:
    int team_id_;
    std::string name_;
	int type_;
    Player player_;

    // установить кружок команды
    void setTeamImage();
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

	virtual void set_position(Position pos) {};

	void set_team_id(int id);

    virtual void move(int speed) {};
    virtual void rotate(double angle) {};
    virtual void fire() {};
};

#endif // UNIT_H
