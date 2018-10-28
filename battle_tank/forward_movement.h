#ifndef FORWARD_MOVEMENT_H
#define FORWARD_MOVEMENT_H
#include "movement.h"
class ForwardMovement : public Movement
{
public:
    ForwardMovement(int max_speed, int max_back_speed) : Movement(max_speed), max_back_speed_(max_back_speed){};
    ~ForwardMovement();

    int get_max_back_speed() const;
    void set_max_back_speed(int);

private:
    int max_back_speed_;
};

#endif // FORWARD_MOVEMENT_H
