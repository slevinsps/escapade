#ifndef BASE_VISUALIZER_H
#define BASE_VISUALIZER_H
#include "scene.h"
#include "user_control_bundle.h"
#include "Tank.h"
class BaseVisualizer
{
public:
	BaseVisualizer() { control_tank = -1; };
	//virtual ~BaseVisualizer();

	TScene base_get_scene() const {
		return tScene_;
	};

	int load_user_units() {
		// Приходит из другой сцены, пока так
		
		int amount = 2;
		// Загрузка пользователей
		std::vector<User> load_users;

		for (size_t i = 0; i < amount; i++) {
			load_users.push_back(User("player" + i,
				i, PLAYER, false));
		} 

		// Загрузка алгоритмов
		std::vector<UnitControl> load_alg;
		for (size_t i = 0; i < amount; i++) {
			load_alg.push_back(UnitControl());
		}

		//Загрузка танков
		std::vector<Tank> load_tanks;
		for (size_t i = 0; i < amount; i++) {
			Player player(load_users[i]);
			load_tanks.push_back(Tank(player, 0, "lol"));
			load_tanks.back().setModel(i % 2);
			load_tanks.back().setName("Ivan"+std::to_string(i));
		}

		std::vector<UserControlBundle> load_user_units;
		// Инициализация контроллируемых юнитов
		for (size_t i = 0; i < amount; i++) {
			load_user_units.push_back(UserControlBundle(
				load_users[i], load_alg[i],
				load_tanks[i]));
		}
		
		user_units = std::move(load_user_units);

		return 0;
	}

	// Return i if user_units[i] exists, else  -1
	int get_user_unit(int i) {
		if (i < 0 || i >= user_units.size()) {
			return -1;
		}
		return i;
	}

protected:
	TScene tScene_;
	int control_tank; // выбор танка для управления с клавиатуры

	std::vector<UserControlBundle> user_units;

	void set_scene(TScene tScene) { tScene_ = tScene; }
};
#endif // BASE_VISUALIZER_H
