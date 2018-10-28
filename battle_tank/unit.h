#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "sceneobject.h"
#include "component.h"

class Unit : public SceneObject
{
private:
    int team_id;
    std::string name;

    // установить кружок команды
    void setTeamImage();
public:
    // Явное указание игрока и команды
    Unit(int _team_id,
         Position _position = Position(),
         QImage _texture = QImage("red_circle.png")) :
         SceneObject(_position, _texture),
         team_id(_team_id){}

    // Является ли юнит союзником
    bool is_friend(const Unit& unit) const;

    int get_team_id() const;
    std::string get_name() const;

    void move();
    void rotate();
    void fire();
};

#endif // UNIT_H
