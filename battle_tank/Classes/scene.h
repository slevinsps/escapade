#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "bonuscontrol.h"
#include "loader.h"
#include "map.h"
#include "socket.h"
#include "tank.h"
#include "unit.h"

#define BITMASK_NOBODY 0x00000000
#define BITMASK_BULLET 0x00000001
#define BITMASK_ALIVE_UNIT 0x00000002
#define BITMASK_DEAD_UNIT 0x00000004

// Tank Scene
class TScene {
 public:

  TScene(std::vector<Tank> units) {
    units_ = units;
    init();
  }

  TScene() = default;

  std::vector<Tank>& getUnits();
  void setUnits(std::vector<Tank> units);

  bonusControl& getBonusControl();
  void setBonusControl(bonusControl bonus);

  bool operator==(const TScene& other) const;

  bool operator!=(const TScene& other) const;

  std::vector<std::vector<cocos2d::Node*>> collisions_;
  std::vector<std::vector<cocos2d::Node*>> attackers_;
  std::vector<std::vector<cocos2d::Node*>> other_;

  // Установка маски живого танка
  void make_alive(int id) {
    for (Node* collision : collisions_[id]) {
      PhysicsBody* body = collision->getPhysicsBody();
      body->setCategoryBitmask(BITMASK_ALIVE_UNIT);
    }
  }

  BattleMap* TScene::getMap();
  void TScene::setMap(BattleMap* map);

  // Установка маски танка-мертвеца
  void make_died(int id) {
    for (Node* collision : collisions_[id]) {
      PhysicsBody* body = collision->getPhysicsBody();
      body->setCategoryBitmask(BITMASK_DEAD_UNIT);
    }
  }

  void new_match() {
	  // Цикл для визуализатора
    int i = 0;
    for (int i = 0; i < units_.size(); i++) {
      make_alive(i);
    }
	// Цикл для логики
    for (Unit& unit : units_) {
      unit.launch();
    }
  }

  void init() {
    // Для каждого юнита
    for (Unit& unit : units_) {
      std::vector<SpriteSceneObject*> collisions;
      unit.ColiisionObjects(collisions);

      std::vector<SpriteSceneObject*> attackers;
      unit.Attackers(attackers);

	  std::vector<SpriteSceneObject*> other;
      unit.OtherObjects(other);

      // Устанавливаем корректные маски битов
      // подробнее -
      // http://www.cocos2d-x.org/reference/native-cpp/V3.8/d7/d7b/classcocos2d_1_1_physics_body.html#a6850ee6e1b1aec30b38556ceed1fc4b3

	   std::vector<cocos2d::Node*> row;

      // Для атакующих
      for (SpriteSceneObject* attacker : attackers) {
             row.push_back(
            SpriteSceneObjectCocos::Node(
				attacker, ALIVE_SCENEOBJECT));
                
        PhysicsBody* body = row.back()->getPhysicsBody();
                    // setCategoryBitmask - к какой категории относятся атаккеры
        body->setCategoryBitmask(BITMASK_BULLET);

        // setContactTestBitmask - какие тела с помощью слушателей могут узнать,
        // что в них врезались атакующие
        body->setContactTestBitmask(BITMASK_ALIVE_UNIT);

        // setCollisionBitmask - в какие тела могут врезаться аттакеры(если они
        // тут не оказаны, атакер пролетит сквозь)
        body->setCollisionBitmask(BITMASK_BULLET + BITMASK_ALIVE_UNIT);
      }
      attackers_.push_back(row);

	  row.clear();
      // Для юнитов
      for (SpriteSceneObject* collision : collisions) {
            row.push_back(
            SpriteSceneObjectCocos::Node(collision, ALIVE_SCENEOBJECT));

        PhysicsBody* body = row.back()->getPhysicsBody();
        // setContactTestBitmask - какие тела с помощью слушателей могут узнать,
        // что в них врезались части юнита
        body->setContactTestBitmask(BITMASK_BULLET + BITMASK_ALIVE_UNIT);

        // setCollisionBitmask - в какие тела могут врезаться чсти юнита
        body->setCollisionBitmask(BITMASK_BULLET + BITMASK_ALIVE_UNIT);
      }
      collisions_.push_back(row);

	  row.clear();
	  // Остальное
          for (SpriteSceneObject* obj : other) {
			 row.push_back(SpriteSceneObjectCocos::Node(obj, ALIVE_SCENEOBJECT));

      }
      other_.push_back(row);
      row.clear();
    }

    new_match();
  }

 protected:
  std::vector<Tank> units_;
  BattleMap* map_;
  bonusControl bonuses_;
};
#endif  // SCENE_H
