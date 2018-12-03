#ifndef TANK_H
#define TANK_H
#include "unit.h"
#include "weapon.h"
#include "body.h"

class Tank : public Unit
{
public:
	Tank(std::string name = "unknown tank",
		int type = LIGHT,
		Position position = Position(),
		std::string = "circle");
    Weapon& get_weapon();
    Body& get_body();

	void launch() {
		Unit::launch();
		sprite->setTexture("circle.png");
	}

	void destroy() {
		Unit::destroy();
		sprite->setRotation(0);
		sprite->setTexture("died135.png");
	}
	
	void move(float power, bool back) override;
	
	void rotate_body(float power, bool clockwise) override;
	
	void rotate_weapon(float power, bool clockwise) override;
	
	void fire(int shot) override;

	void setModel(int type) override;

    void set_position(Position pos) override;

	void center_weapon() override;

    void sinchronize() override;

	bool is_alive() override {
		return body_.get_health() > 0;
	}

	void damage(int damage) override {
		body_.decrement_helth(damage);
	}

	// Массив объектов cocos2d::сцены(для добавления на сцену)
	void SceneNodes(std::vector<cocos2d::Node*>& nodes) override  {
		nodes.clear();
		CCLOG("IN RIGHT PLACE");

		nodes.push_back(body_.sprite); // спрайт корпуса
		nodes.push_back(body_.bar_); // индикатор здоровья
		nodes.push_back(weapon_.sprite); // спрайт пушки
		
		for (Bullet& bullet : weapon_.get_bullets()) {
			nodes.push_back(bullet.sprite); // спрайты пуль
		}

		nodes.push_back(weapon_.bar_); // индикатор перезарядки
		nodes.push_back(sprite); // кружок, летающий вокруг танка
		nodes.push_back(unit_name); // Подпись с именем игрока
	}

	// Получить компоненты юнита, участвующие в коллизиях
	void ColiisionObjects(std::vector<cocos2d::PhysicsBody*>& bodies) override {
		bodies.push_back(body_.sprite->getPhysicsBody()); // спрайт корпуса
	}

	// Получить атакующие объекты юнита(для танков - пули)
	void Attackers(std::vector<cocos2d::PhysicsBody*>& bodies) override {
		for (Bullet& bullet : weapon_.get_bullets()) {
			bodies.push_back(bullet.sprite->getPhysicsBody()); // спрайты пуль
		}
	}

private:
    Weapon weapon_;
    Body body_;

};

#endif // TANK_H
