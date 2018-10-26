#ifndef BULLET_H
#define BULLET_H

#include "sceneobject.h"

#define BULLET_READY_TO_FIRE 0 // Пуля в пушке
#define BULLET_IS_FLYING 1// В полете
#define BULLET_FLOWN -1// Улетела

#define BULLET_DEFAULT_SPEED 100

class Bullet : public SceneObject
{
public:
    Bullet(int _speed = BULLET_DEFAULT_SPEED,
           Position _position = Position(),
           QImage _texture = QImage("bullet.png")) :
        SceneObject(_position, _texture),
        speed(_speed), point_of_departure(position),
        status(BULLET_READY_TO_FIRE){}
    
    void get_speed();

    void isDistanceMax();
private:
    int speed;
    Position point_of_departure;
    int range;
    int status;
};

#endif // BULLET_H
