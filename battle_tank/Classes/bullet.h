#ifndef BULLET_H
#define BULLET_H

#include "sceneobject.h"
#include "rotational_movement.h"
#include "forward_movement.h"
#include "rotational_movement.h"

#define BULLET_DEFAULT_RANGE 200
#define BULLET_DEFAULT_FORWARD_SPEED 100
#define BULLET_DEFAULT_ROTATION_SPEED 0

class Bullet : public SceneObject
{
public:
    // Явное задание первых двух параметров, чтобы вызывающие
    // классы точно передавали сюда позицию и угол юнита
	Bullet(
		Position pos, float range = BULLET_DEFAULT_RANGE,
		float forward_speed = BULLET_DEFAULT_FORWARD_SPEED,
		float rotation_speed = BULLET_DEFAULT_ROTATION_SPEED,
		std::string texture = "bullet");
    
    ForwardMovement& get_forward_movement();
    bool get_islaunch();
    int get_range();
    bool is_distance_max();
    void count_range();
	int move();

private:
    Position begin_point_;
    int range_;
	int damage_;
	// Пока что нет идентификатора, какой игрок нанес урон... на выходных поправим
    bool isLaunch_;
    ForwardMovement forward_;
    RotateMovement rotation_;
};

#endif // BULLET_H
