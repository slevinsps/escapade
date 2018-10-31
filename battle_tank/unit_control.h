#ifndef UNIT_CONTROLL_H
#define UNIT_CONTROLL_H

#include "unit.h"
#include "baseunitcontrol.h"
#include <string>

class UnitControl : public BaseUnitControl
{
public:
    UnitControl(){}
    ~UnitControl(){}

    std::string name_of_tank;
    double version;
    int tank_model;

    void run(Unit unit){
         unit.fire();
    }
};

#endif // TANK_CONTROL_H
