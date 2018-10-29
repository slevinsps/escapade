#include "room.h"

Room::Room(int max_amount_of_players, int max_of_matches):
    static_parameters_(StaticRoomParameters(max_amount_of_players, 1,1,1,max_of_matches)),
    isEverybodyOK_(false){
   }

bool Room::operator == (const Room &other) const
{
    return this->users_ == other.getUsers();
}

bool Room::operator != (const Room &other) const
{
    return this->users_ != other.getUsers();
}

std::vector<User> Room::getUsers() const {
    return users_;
}

Room::~Room(){};

int Room::load(Socket socket) {return 0;};
int Room::send(Socket socket) {return 0;};

int Room::add_user(User& user) {
    users_.push_back(user);
    return SUCCESS;
}

int Room::find_user(User &) {
     return SUCCESS;
}

int Room::remove_user(User&) {
     return SUCCESS;
}
