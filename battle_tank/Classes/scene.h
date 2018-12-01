#ifndef SCENE_H
#define SCENE_H


#include <vector>

#include "unit.h"
#include "socket.h"
#include "map.h"
#include "loader.h"
#include "bonuscontrol.h"
#include "tank.h"


// Tank Scene
class TScene
{
public:
	// Временное решение, пока нет препятствий и бонусов
	TScene(std::vector<Tank> units) { units_ = units; }

	// Ниже не отредактированные функции, отредактируем завтра

	TScene() = default;
	TScene(std::vector<Tank> units,
		BattleMap map,
          bonusControl bonuses) :
             units_(units), map_(map), bonuses_(bonuses){};

    std::vector<Tank>& getUnits();
    void setUnits(std::vector<Tank> units);

	BattleMap& getMap();
    void setMap(BattleMap map);

    bonusControl& getBonusControl();
    void setBonusControl(bonusControl bonus);

    bool operator == (const TScene &other) const;

    bool operator != (const TScene &other) const;

private:
    std::vector<Tank> units_;
	BattleMap map_;
    bonusControl bonuses_;
};
#endif // SCENE_H
