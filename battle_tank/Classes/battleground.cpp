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

Room& BattleGround::get_room() {
    return room_;
}

TScene& BattleGround::get_scene() {
	return scene_;
}

std::vector<UnitControl>& BattleGround::get_algorithms() {
    return algorithms_;
}
/*
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
