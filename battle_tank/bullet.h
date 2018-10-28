#ifndef BULLET_H
#define BULLET_H

#include "sceneobject.h"
#include "rotationalmotion.h"
#include "forwardmovement.h"

#define BULLET_DEFAULT_FORWARD_SPEED 500
#define BULLET_DEFAULT_ROTATION_SPEED 0

class Bullet : public SceneObject
{
public:
    // Явное задание первых двух параметров, чтобы вызывающие
    // классы точно передавали сюда позицию и угол юнита
    Bullet(Position _position, double angle,
           int _speed = BULLET_DEFAULT_FORWARD_SPEED,
           QImage _texture = QImage("bullet.png")) :
        SceneObject(_position, _texture),
        point_of_departure(position),
        forward(_speed,_speed),
        rotation(BULLET_DEFAULT_ROTATION_SPEED, angle),
        isFly(false){}
    
    void get_speed();

    void isDistanceMax();
private:
    Position point_of_departure;
    int range;
    bool isFly;
    ForwardMovement forward;
    RotationalMotion rotation;
};

#endif // BULLET_H
