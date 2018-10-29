#include "dynamic_room_parameters.h"

DimaicRoomParameters::DimaicRoomParameters() :
                 cur_amount_of_players_(0),
                 status_(0),
                 cur_amount_of_matches(0){}

DimaicRoomParameters::~DimaicRoomParameters(){}

int DimaicRoomParameters::get_amount_of_players() const{
    return cur_amount_of_players_;
}

void DimaicRoomParameters::set_amount_of_players(int players) {
    cur_amount_of_players_ = players;
}

int DimaicRoomParameters::get_status() const {
     return status_;
}
void DimaicRoomParameters::set_status(int status) {
    status_ = status;
}

int DimaicRoomParameters::get_amount_of_matches() const {
     return cur_amount_of_matches;
}

void DimaicRoomParameters::set_amount_of_matches(int matches) {
     cur_amount_of_matches = matches;
}
