#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H

#include <vector>

#include "scene.h"
#include "room.h"
#include "user_control_bundle.h"

class BattleGround
{
public:
    BattleGround(TScene& tscene,
                 Room room,
                 std::vector<UnitControl>& bundles);
    virtual ~BattleGround();

    //void add_bundle(UserControlBundle);

	TScene& get_scene();

    Room& get_room();
    void set_room(Room room);

    std::vector<UnitControl>& get_algorithms();
    //void set_control_bundle(std::vector<UserControlBundle> bundles);

	static BattleGround offline(User user, int amount);

	// Один танк атаковал другого. Возвращает был ли танк убит
	// Выглядит монструозно, в будущем сократим. В поле боя хранится сцена(scene_). Нам необходим массив юнитов -
	// он лежит в сцене, получаем этот массив функцией getUnits(). Итак, у нас на руках массив юнитов, надо понять какой
	// танк должен получить урон. Каждый объект сцены(сам танк, корпус, пушка, пули) хранит в себе поле sprite.
	// sprite может иметь целочисленное поле tag. Создавая объект класса Визуализатора каждый объект сцены получил тег
	// соответсующий своему танку(индекс в массиве юнитов). Если быть конкретным, это происходит в функции add_players().
	// Поскольку теги используются не только в спрайтах танков, но и во всех остальных cocos2d::Node, в той функции присваи
	// ваются не просто индексы, а индексы + TAG_PLAYERS_UNITS(define прописанный в заголовочном файле Визуализатора)
	// Итак, чтобы идентифицировать танк, надо получить тег спрайта - a->getTag() - TAG_PLAYERS_UNITS. Вот мы и получили 
	// танк, который получит урон, осталось понять какой урон надо нанести. Тем же способом определяем какому танку принадлежит
	// выпущенная пуля(у пули тот же тег, что и у всех остальных компонентов i-ого танка). Все, у нас есть танк, которому надо
	// нанести урон и мы знаем какой именно. Вызываем юнитовскую функцию damage(int).
	void attack(int defender, int attacker) {
		int damage = scene_.getUnits()[attacker].get_weapon().get_damage();
		scene_.getUnits()[defender].damage(damage);
		room_.players_[defender].increase_damage_received(damage);
		room_.players_[attacker].increase_damage_done(damage);

		if (!scene_.getUnits()[defender].is_alive()) {
			scene_.make_died(scene_.getUnits()[defender]);
			scene_.getUnits()[defender].destroy();
			room_.players_[defender].increase_deaths();
			room_.players_[attacker].increase_kills();
		}
	}

	TScene scene_;
	Room room_;
	std::vector<UnitControl> algorithms_;
private:
	;
};
#endif // BATTLEGROUND_H
