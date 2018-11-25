#include "dynamic_room_parameters.h"

DynamicRoomParameters::DynamicRoomParameters() :
                 cur_amount_of_players_(0),
                 status_(0),
                 cur_amount_of_matches(0){}

DynamicRoomParameters::~DynamicRoomParameters(){}

int DynamicRoomParameters::get_amount_of_players() const{
    return cur_amount_of_players_;
}

void DynamicRoomParameters::set_amount_of_players(int players) {
    cur_amount_of_players_ = players;
}

int DynamicRoomParameters::get_status() const {
     return status_;
}
void DynamicRoomParameters::set_status(int status) {
    status_ = status;
}

int DynamicRoomParameters::get_amount_of_matches() const {
     return cur_amount_of_matches;
}

void DynamicRoomParameters::set_amount_of_matches(int matches) {
     cur_amount_of_matches = matches;
}
