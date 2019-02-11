#ifndef BULLET_H
#define BULLET_H

#include "forward_movement.h"
#include "rotational_movement.h"
#include "sceneobject.h"

#define BULLET_DEFAULT_RANGE 200
#define BULLET_DEFAULT_FORWARD_SPEED 5
#define BULLET_DEFAULT_ROTATION_SPEED 0
#define BULLET_DEFAULT_THROUHT_PASS 0

#define BULLET_TYPE_LIGHT 0
#define BULLET_TYPE_HEAVY 1

class Bullet : public SpriteSceneObject {
 public:
  // Явное задание первых двух параметров, чтобы вызывающие
  // классы точно передавали сюда позицию и угол юнита
  Bullet(Position pos, float range,
         float forward_speed = BULLET_DEFAULT_FORWARD_SPEED,
         float rotation_speed = BULLET_DEFAULT_ROTATION_SPEED,
         float curr_angle = 0, int pass = BULLET_DEFAULT_THROUHT_PASS,
         std::string texture = "bullet");

  int get_range() const;
  int get_pass_throught() const;

  static Bullet lightBullet(Position pos) {
    return Bullet(pos, 150.f, 8, 0, 0, 0, "bullet");
  }

  static Bullet heavyBullet(Position pos) {
    return Bullet(pos, 400.f, 20, 0, 0, 3, "tank_heavy_bullet");
  }

  // Попадание в танк
  void hit();

  // Продолжать движение?
  bool continue_moving();

  void SetAngle(float angle) { rotation_.set_current_angle(angle); }

  void SetPosition(Position pos) { forward_.set_pos(pos); }

  int move();

  bool IsFlying() { return forward_.IsActive();
  }

  ForwardMovement forward_;
  RotateMovement rotation_;

 private:
  int pass_throught_units_times;
  int range_;
};

#endif  // BULLET_H
