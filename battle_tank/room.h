#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "user_control_bundle.h"
#include "static_room_parameters.h"
#include "dynamic_room_parameters.h"

#define SUCCESS 0
#define ROOM_IS_FULL -1
#define ROOM_IS_EMPTY -2

const int ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS = 4;
const int ROOM_DEFAULT_AMOUNT_OF_MATCHES = 3;

class Room : public Loader
{
public:
    Room(int max_amount_of_players = ROOM_DEFAULT_MAX_NUMBER_OF_PLAYERS,
         int max_of_matches = ROOM_DEFAULT_AMOUNT_OF_MATCHES);

    ~Room();

    int add_user(User&);

    int find_user(User &);

    int remove_user(User&);

    int load(Socket socket) override;
    int send(Socket socket) override;

    std::vector<User> getUsers() const;

    bool operator == (const Room &other) const;

    bool operator != (const Room &other) const;


private:
    DimaicRoomParameters dynamic_parameters_;
    StaticRoomParameters static_parameters_;
    std::vector<User> users_;
    // Работает каждый алгоритм
    // Количество игроков не превышает максимум
    // Все подтвердили готовность
    bool isEverybodyOK_;
};
#endif // ROOM_H
