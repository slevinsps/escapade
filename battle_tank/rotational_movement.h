#ifndef ROTATIONALMOTION_H
#define ROTATIONALMOTION_H

#include "movement.h"

#define ROTATION_MOVEMENT_DEFAULT_SPEED 0
#define ROTATION_MOVEMENT_DEFAULT_ANGLE 0

#define ROTATE_MOVEMENT_H

#include "movement.h"
class RotateMovement : public Movement
{
public:
    RotateMovement(int max_speed, int current_angle) : current_angle_(current_angle), Movement(max_speed){}
    virtual ~RotateMovement(){}
    int get_current_angle() const;
    void set_current_angle(int);
    const bool operator == (const RotateMovement &v1, const RotateMovement &v2);
private:
    int current_angle_;
};

#endif // ROTATE_MOVEMENT_H

