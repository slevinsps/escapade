#ifndef TANK_H
#define TANK_H
#include "unit.h"
#include "weapon.h"
#include "body.h"

class Tank : public Unit
{
private:
    Weapon weapon;
    Body body;

public:
    Tank(Weapon _weapon, Body _body, Engine _engine,
         int _team_id, std::string name,
         Position position = Position(),
         QImage texture = QImage("red_circle.png")
         ) : Unit(_team_id, name, position, texture), weapon(_weapon), body(_body), engine(_engine){}

    void move(int speed) override;
    void rotate(double angle) override;
    void fire() override;
};

#endif // TANK_H
