#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "user_control_bundle.h"
#include "static_room_parameters.h"
#include "dynamic_room_parameters.h"

const int ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS = 4;
const int ROOM_DEFAULT_AMOUNT_OF_MATCHES = 3;

class Room : public Loader
{
public:
    Room();
    Room(int max_amount_of_players = ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS,
         int max_of_matches = ROOM_DEFAULT_AMOUNT_OF_MATCHES) : isEverybodyOK_(false){
        static_parameters_.set_max_of_players(max_amount_of_players);
        static_parameters_.set_max_of_matches(max_of_matches);
    }
    ~Room();


    int add_user(User&);
    int remove_user(User&);

private:
    DimaicRoomParameters dynamic_parameters_;
    StaticRoomParameters static_parameters_;
    std::vector<User&> users_;
    // Работает каждый алгоритм
    // Количество игроков не превышает максимум
    // Все подтвердили готовность
    bool isEverybodyOK_;

};

#endif // ROOM_H
