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

    void collect_health() override;
    void collect_speed() override;
    void collect_damage() override;

public:
    Tank(Weapon _weapon = Weapon(),
         Body _body = Body(),
         Engine _engine = Engine()) :
    weapon(_weapon), body(_body), engine(_engine){}

    // Является ли юнит союзником
    virtual bool isFriendlyFire(const Unit& unit) const;


};

#endif // TANK_H
