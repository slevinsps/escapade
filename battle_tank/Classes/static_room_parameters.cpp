#include "static_room_parameters.h"

void StaticRoomParameters::set_max_of_players(int max_amount_of_players) {
    max_amount_of_players_ = max_amount_of_players;
}

void StaticRoomParameters::set_time_limit(int time_limit) {
    time_limit_ = time_limit;
}

void StaticRoomParameters::set_time_start(int time_start) {
    time_start_ = time_start;
}

void StaticRoomParameters::set_max_of_matches(int max_amount_of_matches) {
    max_amount_of_matches_ = max_amount_of_matches;
}

StaticRoomParameters::~StaticRoomParameters(){}
