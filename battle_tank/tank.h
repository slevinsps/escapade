#ifndef TANK_H
#define TANK_H
#include "unit.h"
#include "weapon.h"
#include "body.h"

class Tank : public Unit
{
public:
    Tank(Weapon weapon, Body body,
         int team_id, std::string name,
         Position position = Position(),
         QImage texture = QImage("red_circle.png")
         ) : Unit(team_id, name, position, texture), weapon(weapon), body(body){}

    Weapon& get_weapon();
    Body& get_body();
    void move(int speed) override;
    void rotate(double angle) override;
    void fire() override;

private:
    Weapon weapon;
    Body body;

};

#endif // TANK_H
