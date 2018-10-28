#ifndef PLAYER_H
#define PLAYER_H

#include "user.h"

class Player: public User
{
public:
    Player();
private:
    int kills;
    int deaths;

};

#endif // PLAYER_H
