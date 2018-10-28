#ifndef TANK_H
#define TANK_H
#include "unit.h"
#include "weapon.h"
#include "body.h"
#include "engine.h"

class Tank : public Unit
{
private:
    Weapon weapon;
    Body body;
    Engine engine;

public:
    Tank(Weapon _weapon, Body _body, Engine _engine,
         int _team_id,
         Position _position = Position(),
         QImage _texture = QImage("red_circle.png")
         ) : Unit(_team_id, _position, _texture), weapon(_weapon), body(_body), engine(_engine){}
};

#endif // TANK_H
