#ifndef BASEUNITCONTROL_H
#define BASEUNITCONTROL_H

class BaseUnitControl
{
public:
	BaseUnitControl() {}
	~BaseUnitControl() {}
	virtual void init(Unit &unit) {};

	virtual void run(Unit &unit) {};
};
#endif // BASEUNITCONTROL_H
