#ifndef PLAYER_H
#define PLAYER_H

#include "user.h"

class Player: public User
{
public:
    Player(int kills = 0, int deaths = 0);

	Player(User user);

    int get_kills() const;

    void increase_kills();

    int get_deaths() const;

    void increase_deaths();

private:
    int kills_;
    int deaths_;
};

#endif // PLAYER_H
