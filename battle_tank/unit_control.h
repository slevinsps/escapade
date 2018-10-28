#ifndef TANK_CONTROL_H
#define TANK_CONTROL_H

#include "unit.h"
#include <string>

class UnitControl
{
public:
    UnitControl();

    std::string name_of_tank;
    double version;
    int tank_model;

    void run(Unit unit){
         unit.fire();
    }
};

#endif // TANK_CONTROL_H
