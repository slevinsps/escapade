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
    Tank(Weapon _weapon, Body _body, Engine _engine) :
    weapon(_weapon), body(_body), engine(_engine){}

};

#endif // TANK_H
