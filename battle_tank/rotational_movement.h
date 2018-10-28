#ifndef ROTATIONALMOTION_H
#define ROTATIONALMOTION_H

#include "movement.h"

#define ROTATION_MOVEMENT_DEFAULT_SPEED 0
#define ROTATION_MOVEMENT_DEFAULT_ANGLE 0

class RotationalMotion: public Movement
{
public:
    RotationalMotion(int _speed = ROTATION_MOVEMENT_DEFAULT_SPEED,
                    int _angle = ROTATION_MOVEMENT_DEFAULT_ANGLE
                    )
        : current_speed(_speed), angle(_angle){}

    int getAngle() const;
    int getMaxSpeed() const;
    int getMaxBackSpeed() const;

    // В установке угла нет необходимости
    //void setAngle(int angle);

    //
    void setMaxSpeed(int speed);
    void setMaxBackSpeed(int speed);
private:
    float current_speed;

    // Не задается const, поскольку может меняться бонусом
    float angle;
};

#endif // ROTATIONALMOTION_H
