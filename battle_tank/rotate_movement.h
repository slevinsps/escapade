#ifndef ROTATE_MOVEMENT_H
#define ROTATE_MOVEMENT_H
#include "movement.h"
class RotateMovement : public Movement
{
public:
    RotateMovement(int max_speed) : Movement(max_speed){};
    ~RotateMovement();

    int get_current_angle() const;
    void set_current_angle(int);

private:
    int current_angle_;
};

#endif // ROTATE_MOVEMENT_H
