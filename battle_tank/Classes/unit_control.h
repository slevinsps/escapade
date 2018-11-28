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

    double version;

	// Сначала вызывается init, потом run,
	// init необходим для инициализации переменных

	void init(Unit& unit) {
		unit.setModel(LIGHT);
		unit.setName("No name");
	}

    void run(Unit& unit){
		;
    }
};

#endif // TANK_CONTROL_H
