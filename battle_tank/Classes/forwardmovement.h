#ifndef FORWARDMOVEMENT_H
#define FORWARDMOVEMENT_H

#include "movement.h"

#define FORWARD_MOVEMENT_DEFAULT_SPEED 0
#define FORWARD_MOVEMENT_DEFAULT_MAX_SPEED 100
#define FORWARD_MOVEMENT_DEFAULT_MAX_BACKSPEED -30

class ForwardMovement: public Movement
{
public:
    ForwardMovement(int _speed = FORWARD_MOVEMENT_DEFAULT_SPEED,
                    int _max_speed = FORWARD_MOVEMENT_DEFAULT_MAX_SPEED,
                    int _max_backspeed = FORWARD_MOVEMENT_DEFAULT_MAX_BACKSPEED)
        : current_speed(_speed), max_speed(_max_speed),
          max_backspeed(_max_backspeed){}

    int getSpeed() const;
    int getMaxSpeed() const;
    int getMaxBackSpeed() const;

    void setSpeed(int speed);
    void setMaxSpeed(int speed);
    void setMaxBackSpeed(int speed);
private:
    int current_speed;

    // Не задается const, поскольку может меняться бонусом
    int max_speed;
    int max_backspeed;
};

#endif // FORWARDMOVEMENT_H
