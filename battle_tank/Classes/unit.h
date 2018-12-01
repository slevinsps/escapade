#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "sceneobject.h"
#include "player.h"

// Тип танка
enum types {
	LIGHT = 0,
	HARD = 1
};

// Тип выстрела
enum shot_types {
	ONE = 0,
	BURST = 1,
	ALL = 2
};

class Unit : public SceneObject
{
private:
    std::string name_;
	int type_;
	bool runnable; // Флаг контроля

public:
	cocos2d::Label* unit_name;

    // Явное указание игрока и команды
	Unit(std::string name = "unnamed unit",
		int type = LIGHT,
         Position _position = Position(),
         std::string texture = "circle");

    ~Unit();

	// Обязательная функция запуска, ставит runnable в true
	// если runnable false поток управления прекращает работу
	void launch();

	// Вызывается при уничтожении юнита, ставит runnable в false
	void destroy();
	// Все сеттеры доступны только тогда, когда runnable = false
	
    std::string get_name() const;

    bool operator == (const Unit &other) const;

    bool operator != (const Unit &other) const;

	void setName(std::string name);

	virtual void setModel(int type);

	// Устанавливает одинаковое положение(позицию и угол) для всех объектов юнита
	// В частности для корпуса: Корпус, Пушка, Ник, полоса здоровья, перезарядки и т.д.
	virtual void sinchronize() {};

	virtual void set_position(Position pos) {};

	// power - процент от максимальной скорости
	// back - флаг движения назад
	virtual void move(float power, bool back) {};

	// power - процент от максимальной скорости
	// clockwise - флаг движения по часовой
    virtual void rotate_body(float power, bool clockwise) {};

	// power - процент от максимальной скорости
	// clockwise - флаг движения по часовой
	virtual void rotate_weapon(float power, bool clockwise) {};

	// Отцентрировать пушку
	virtual void center_weapon() {};

	// Тип выстрела - см. структуру shot_types
    virtual void fire(int shot) {};
};

#endif // UNIT_H
