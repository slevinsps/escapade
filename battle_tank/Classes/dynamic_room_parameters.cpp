#include "dynamic_room_parameters.h"

DynamicRoomParameters::DynamicRoomParameters(size_t players) { start(players); };

DynamicRoomParameters::~DynamicRoomParameters(){}

void DynamicRoomParameters::start(size_t players) {
	cur_amount_of_players_ = players;
	cur_amount_of_matches = 0;
}

void DynamicRoomParameters::new_match(size_t players) {
	cur_amount_of_matches++;
	cur_amount_of_players_ = players;
}

void DynamicRoomParameters::kill() {
	cur_amount_of_players_--;
}

int DynamicRoomParameters::players() const {
	return cur_amount_of_players_;
}

int DynamicRoomParameters::matchs() const {
	return cur_amount_of_matches;
}