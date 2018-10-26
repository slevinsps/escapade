#ifndef TANK_CONTROL_H
#define TANK_CONTROL_H

#include "tank.h"
#include <string>

class UnitControl
{
public:
    UnitControl();

    const int id = 1;
    const std::string name;

    void run(Tank tank){
         tank.fire();
    }
};

#endif // TANK_CONTROL_H
