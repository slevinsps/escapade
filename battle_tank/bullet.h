#ifndef BULLET_H
#define BULLET_H

#include "sceneobject.h"
#include "rotational_movement.h"
#include "forward_movement.h"
#include "rotational_movement.h"

#define BULLET_DEFAULT_FORWARD_SPEED 500
#define BULLET_DEFAULT_ROTATION_SPEED 0

class Bullet : public SceneObject
{
public:
    // Явное задание первых двух параметров, чтобы вызывающие
    // классы точно передавали сюда позицию и угол юнита
    Bullet(Position position_begin = Position(),
           Position position_cur = Position(),
           double angle = 0,
           int speed = BULLET_DEFAULT_FORWARD_SPEED,
           QImage texture = QImage("bullet.png")) :
        SceneObject(position_cur, texture),
        begin_point_(position_begin),
        forward_(speed,speed),
        rotation_(BULLET_DEFAULT_ROTATION_SPEED, angle),
        isLaunch_(false),
        range_(0){}
    
    ForwardMovement& get_forward_movement();
    bool get_islaunch();
    int get_range();
    bool is_distance_max();
    void count_range();
    int move();

private:
    Position begin_point_;
    int range_;
    bool isLaunch_;
    ForwardMovement forward_;
    RotateMovement rotation_;
};

#endif // BULLET_H
