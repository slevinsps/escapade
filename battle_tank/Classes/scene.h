#ifndef SCENE_H
#define SCENE_H


#include <vector>

#include "unit.h"
#include "socket.h"
#include "map.h"
#include "loader.h"
#include "bonuscontrol.h"
#include "tank.h"

#define BITMASK_NOBODY 0x00000000
#define BITMASK_BULLET 0x00000001
#define BITMASK_ALIVE_UNIT 0x00000002
#define BITMASK_DEAD_UNIT 0x00000004


// Tank Scene
class TScene
{
public:
	// Временное решение, пока нет препятствий и бонусов
	TScene(std::vector<Tank> units) { 
		units_ = units;
		init();
	}

	// Ниже не отредактированные функции, отредактируем завтра
	
	TScene() = default;
	/*
	TScene(std::vector<Tank> units,
		BattleMap map,
          bonusControl bonuses) :
             units_(units), map_(map), bonuses_(bonuses){};
	*/
    std::vector<Tank>& getUnits();
    void setUnits(std::vector<Tank> units);

	BattleMap& getMap();
    void setMap(BattleMap map);

    bonusControl& getBonusControl();
    void setBonusControl(bonusControl bonus);

    bool operator == (const TScene &other) const;

    bool operator != (const TScene &other) const;

	// Установка маски живого танка
	void make_alive(Unit& unit) {
		std::vector<PhysicsBody*> collisions;
		unit.ColiisionObjects(collisions);

		for (PhysicsBody* collision : collisions) {
			collision->setCategoryBitmask(BITMASK_ALIVE_UNIT);
		}
	}

	// Установка маски танка-мертвеца
	void make_died(Unit& unit) {
		std::vector<PhysicsBody*> collisions;
		unit.ColiisionObjects(collisions);

		for (PhysicsBody* collision : collisions) {
			collision->setCategoryBitmask(BITMASK_DEAD_UNIT);
		}
	}

	void new_match() {
		for (Unit& unit : units_) {
			make_alive(unit);
			unit.launch();
		}
	}

	void init() {
		// Для каждого юнита
		for (Unit& unit : units_) {
			std::vector<PhysicsBody*> collisions;
			unit.ColiisionObjects(collisions);

			std::vector<PhysicsBody*> attackers;
			unit.Attackers(attackers);

			// Устанавливаем корректные маски битов
			// подробнее - http://www.cocos2d-x.org/reference/native-cpp/V3.8/d7/d7b/classcocos2d_1_1_physics_body.html#a6850ee6e1b1aec30b38556ceed1fc4b3
			
			// Для атакующих
			for (PhysicsBody* attacker : attackers) {
				// setCategoryBitmask - к какой категории относятся атаккеры
				attacker->setCategoryBitmask(BITMASK_BULLET);
				
				// setContactTestBitmask - какие тела с помощью слушателей могут узнать, что в них врезались атакующие
				attacker->setContactTestBitmask(BITMASK_ALIVE_UNIT);

				// setCollisionBitmask - в какие тела могут врезаться аттакеры(если они тут не оказаны, атакер пролетит сквозь)
				attacker->setCollisionBitmask(BITMASK_BULLET + BITMASK_ALIVE_UNIT);
			}

			// Для юнитов
			for (PhysicsBody* collision : collisions) {
				// setContactTestBitmask - какие тела с помощью слушателей могут узнать, что в них врезались части юнита
				collision->setContactTestBitmask(BITMASK_BULLET + BITMASK_ALIVE_UNIT);

				// setCollisionBitmask - в какие тела могут врезаться чсти юнита
				collision->setCollisionBitmask(BITMASK_BULLET + BITMASK_ALIVE_UNIT);
			}
		}

		new_match();
	}

private:
    std::vector<Tank> units_;
	BattleMap map_;
    bonusControl bonuses_;
};
#endif // SCENE_H
