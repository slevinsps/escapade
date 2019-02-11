#include "room.h"

Room::Room(StaticRoomParameters st,
	DynamicRoomParameters dp,
	std::vector<Player> players) :
	static_parameters_(st),
	dynamic_parameters_(dp),
	players_(players){};

Room Room::offline(User user, int amount) {
	StaticRoomParameters sp = StaticRoomParameters::default();
	DynamicRoomParameters dp(amount);
	std::vector<Player> players(amount, Player(user, -1));

	return Room(sp, dp, players);
}

bool Room::operator == (const Room &other) const
{
    return this->players_ == other.players_;
}

bool Room::operator != (const Room &other) const
{
    return this->players_ != other.players_;
}

Room::~Room(){};