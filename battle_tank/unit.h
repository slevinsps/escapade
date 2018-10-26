#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "sceneobject.h"
#include "component.h"

class Unit : public SceneObject
{
private:
    const int team_id;
    const int current_unit_id;
    std::string name;
protected:
    int health;
    int speed;
    int damage;

    void virtual collect_health() = 0;
    void virtual collect_speed() = 0;
    void virtual collect_damage() = 0;

public:
    static int ID;

    Unit(int _team_id = 0, std::string _name = "Unknown player",
         Position _position = Position(),
         QImage _texture = QImage("red_circle.png")) :
        SceneObject(_position, _texture),
        team_id(_team_id),
        current_unit_id(ID++){}

    // Является ли юнит союзником
    bool is_friendly_fire(const Unit& unit) const;

    int get_health() const;
    int get_speed() const;
    int get_damage() const;

    int get_team_id() const;
    int get_unit_id() const;
    std::string get_name() const;

    void move();
    void rotate();
    void fire();
};

int Unit::ID = 1;

#endif // UNIT_H
