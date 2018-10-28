#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "unit.h"
#include "socket.h"
#include "map.h"
#include "bonuscontrol.h"


class Scene
{
public:
    Scene();
private:
    std::vector<Unit> units;
    Map map;
    bonusControl bonuses;


};

#endif // SCENE_H
