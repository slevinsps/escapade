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

	// ������� ���������� init, ����� run,
	// init ��������� ��� ������������� ����������

	void init(Unit &unit) override {
		unit.setModel(LIGHT);
		unit.setName("No name");
	}

    void run(Unit &unit) override {
		;
    }
};

#endif // TANK_CONTROL_H
