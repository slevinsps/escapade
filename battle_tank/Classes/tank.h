#ifndef TANK_H
#define TANK_H
#include "body.h"
#include "unit.h"
#include "weapon.h"

class Tank : public Unit {
 public:
  Tank(std::string name = "unknown tank", int type = LIGHT,
       Position position = Position(), std::string texture_created = "circle",
       std::string texture_destroyed = "died135");
  Weapon& get_weapon();
  Body& get_body();

  void launch() {
    Unit::launch();
    // sprite->setTexture("circle.png");
  }

  void destroy() {
    Unit::destroy();
    body_.get_forward_movement().set_stop(true);
    for (Bullet& bullet : weapon_.get_bullets()) {
      bullet.forward_.set_stop(true);
    }
    // sprite->setRotation(0);
    // sprite->setTexture("died135.png");
  }

  void move(float distance, bool back, bool keyboard) override;

  void rotate_body(float angle, bool keyboard) override;

  void rotate_weapon(float power, bool clockwise) override;

  void fire(int shot) override;

  void setModel(int type) override;

  // void set_position(Position pos) override;

  void center_weapon() override;

  void synchronize() override;

  bool is_alive() override { return body_.get_health() > 0; }

  virtual int get_health() override { return body_.get_health(); }

  void damage(int damage) override { body_.decrement_helth(damage); }

  // ������ �������� cocos2d::�����(��� ���������� �� �����)
  void SceneNodes(std::vector<SpriteSceneObject*>& nodes) override {
    nodes.clear();

    nodes.push_back(this);  // ������, �������� ������ �����
    nodes.push_back(&body_);    // ������ �������
    nodes.push_back(&weapon_);  // ������ �����
    // nodes.push_back(body_.bar_); // ��������� ��������

    for (Bullet& bullet : weapon_.get_bullets()) {
      nodes.push_back(&bullet);  // ������� ����
    }

    // nodes.push_back(weapon_.bar_); // ��������� �����������

    // nodes.push_back(unit_name); // ������� � ������ ������
  }

  // �������� ���������� �����, ����������� � ���������
  void ColiisionObjects(std::vector<SpriteSceneObject*>& bodies) override {
    bodies.push_back(&body_);  // ������ �������
  }

  // �������� ��������� ������� �����(��� ������ - ����)
  void Attackers(std::vector<SpriteSceneObject*>& bodies) override {
    for (Bullet& bullet : weapon_.get_bullets()) {
      bodies.push_back(&bullet);  // ������� ����
    }
  }

   virtual void OtherObjects(std::vector<SpriteSceneObject*>& bodies) {
    bodies.push_back(&weapon_);  // ������ �����
     bodies.push_back(this);  // ������ ������
   }

     virtual int get_bullets_amount() { return weapon_.get_cur_amount_bullets(); }

 private:
  Weapon weapon_;
  Body body_;
};

#endif  // TANK_H
