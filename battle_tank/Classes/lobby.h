#ifndef LOBBY_H
#define LOBBY_H

#include <vector>.h>

#include "room.h"
#include "loader.h"

class Lobby : public Loader
{
public:
    Lobby();

    int load(Socket socket) override;
    int send(Socket socket) override;
private:
    std::vector<Room> rooms;

    void create_rooms();
};

#endif // LOBBY_H
