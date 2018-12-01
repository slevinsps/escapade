#include "battleground.h"

BattleGround::BattleGround(
             TScene& scene,
             Room room,
             std::vector<UnitControl>& bundles) :
     scene_(scene), room_(room),
	algorithms_(bundles) {}

void BattleGround::set_room(Room room) {
    room_ = room;
}

Room BattleGround::get_room()const {
    return room_;
}
/*
std::vector<UserControlBundle> BattleGround::get_control_bundle() const {
    return bundles_;
}

void BattleGround::set_control_bundle(std::vector<UserControlBundle> bundles) {
    bundles_ = bundles;
}
*/
BattleGround::~BattleGround() {

}

BattleGround BattleGround::offline(User user, int amount) {
	

	// Загрузка пользователей, алгоритмов, танков
	std::vector<User> load_users;
	std::vector<UnitControl> load_alg;
	std::vector<Tank> load_tanks;

	for (int i = 0; i < amount; i++) {
		load_users.push_back(User("player" + i,
			i, PLAYER, false));
		Player player(load_users[i], i);
		load_alg.push_back(UnitControl());

		Tank tank("Ivan"+std::to_string(i), i % 2);
		load_tanks.push_back(tank);
	}

	Room room = Room::offline(user, amount);

	TScene scene_(load_tanks);


	BattleGround BG(scene_, room, load_alg);
	
	return BG;
}
