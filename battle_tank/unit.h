#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "sceneobject.h"
#include "player.h"


class Unit : public SceneObject
{
private:
    int team_id_;
    std::string name_;
    Player player_;

    // установить кружок команды
    void setTeamImage();
public:
    // Явное указание игрока и команды
    Unit(int _team_id,
         std::string name = "unnamed unit",
         Position _position = Position(),
         QImage _texture = QImage("red_circle.png"));

    ~Unit();

    // Является ли юнит союзником
    bool is_friend(const Unit& unit) const;

    int get_team_id() const;
    void set_team_id(int id);

    std::string get_name() const;

    Player get_player() const;
    void set_player(Player player);

    bool operator == (const Unit &other) const;

    bool operator != (const Unit &other) const;



    virtual void move(int speed) {};
    virtual void rotate(double angle) {};
    virtual void fire() {};
};

#endif // UNIT_H
