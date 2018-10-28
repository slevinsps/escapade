#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "unit.h"
#include "socket.h"
#include "map.h"
#include "bonuscontrol.h"


#include "unit.h"
#include "socket.h"
#include "map.h"
#include "loader.h"
#include "bonuscontrol.h"


class Scene : public Loader
{
public:
    Scene(std::vector<Unit>& units,
          Map map,
          bonusControl bonuses) :
             units_(units), map_(map), bonuses_(bonuses){};
    int load(Socket socket) override;
    int send(Socket socket) override;
private:
    std::vector<Unit> units_;
    Map map_;
    bonusControl bonuses_;
};

#endif // SCENE_H
