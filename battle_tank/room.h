#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "user_control.h"

#define ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS 4;
#define ROOM_DEFAULT_AMOUNT_OF_MATCHES 3;

class Room
{
public:
    Room(int _max_amount_of_players = ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS,
         int _amount_of_matches = ROOM_DEFAULT_AMOUNT_OF_MATCHES):
        isEverybodyOK(false),
        max_amount_of_players(_max_amount_of_players),
        amount_of_matches(_amount_of_matches){}
private:
    int max_amount_of_players;
    std::vector<UserControl> controllers;
    // Работает каждый алгоритм
    // Количество игроков не превышает максимум
    // Все подтвердили готовность
    bool isEverybodyOK;
    int amount_of_matches;

};

#endif // ROOM_H
