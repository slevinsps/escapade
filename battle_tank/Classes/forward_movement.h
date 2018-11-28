#ifndef FORWARD_MOVEMENT_H
#define FORWARD_MOVEMENT_H
#include "movement.h"
class ForwardMovement : public Movement
{
public:
    ForwardMovement(int max_speed = 100, int max_back_speed = 50);
    ~ForwardMovement();

	int getSpeed() const;
	int getMaxSpeed() const;
	int getMaxBackSpeed() const;

	void setSpeed(int speed);
	void setMaxSpeed(int speed);
	void setMaxBackSpeed(int speed);

    bool operator == (const ForwardMovement &v1);

private:
    int max_back_speed_;
	int current_speed_;

	// Ќе задаетс€ const, поскольку может мен€тьс€ бонусом
	int max_speed_;
};

#endif // FORWARD_MOVEMENT_H
