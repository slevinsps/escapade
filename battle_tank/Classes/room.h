#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "user_control_bundle.h"
#include "static_room_parameters.h"
#include "dynamic_room_parameters.h"

#define SUCCESS 0
#define ROOM_IS_FULL -1
#define ROOM_IS_EMPTY -2

const int ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS = 4;
const int ROOM_DEFAULT_AMOUNT_OF_MATCHES = 1;

class Room
{
public:
	// Для онлайна использовать обычный конструктор, поскольку все параметры
	// комнаты достаются из форм
	Room(StaticRoomParameters st,
		DynamicRoomParameters dp,
		std::vector<Player> players);

	~Room();

	static Room offline(User user, int amount);

    bool operator == (const Room &other) const;

    bool operator != (const Room &other) const;

	// Идет набор игроков(актуально для онлайна)
	void prepare() {
		static_parameters_.prepare();
	}

	// Битва началась
	void start() {
		static_parameters_.start();
		dynamic_parameters_.start(static_parameters_.players());
		new_match();
	}

	// Попытка запуска нового раунда
	void new_match() {
		// Если сыграно максимальное количество раундов, заканчиваем
		if (no_match_left()) {
			finish();
		}
		else {
			// Иначе обновляем индекс матча и восстанавливаем игроков
			dynamic_parameters_.new_match(static_parameters_.players());
			for (Player& player : players_) {
				player.new_match();
			}
		}
	}

	// Если все игроки погибли или другие причины
	void finish() {
		static_parameters_.finish();
	}

	// После убийства
	void kill(Player killer, Player died) {
		for (Player& player : players_) {
			// == - переопределено в User на сравнение IP
			if (killer == player) {
				killer.increase_kills();
			}
			if (died == player) {
				died.increase_deaths();

				// Если у подбитого не осталось жизней
				dynamic_parameters_.kill();

				// Если остался 1 танк, то завершим битву
				if (one_player_left()) {
					finish();
				}

			} // Без else - вдруг в будущем добавим возможность убить самого себя
		}
	}

	std::vector<Player> players_;
private:

	bool no_match_left() const {
		return dynamic_parameters_.matchs() > static_parameters_.matches();
	}

	// Не подходит для командного режима, но ведь его еще нет, так что не страшно
	bool one_player_left() const {
		return (dynamic_parameters_.players() < 2);
	}

    DynamicRoomParameters dynamic_parameters_;
    StaticRoomParameters static_parameters_;
};

#endif // ROOM_H
