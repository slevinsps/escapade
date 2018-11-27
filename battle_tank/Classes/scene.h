#ifndef SCENE_H
#define SCENE_H


#include <vector>

#include "unit.h"
#include "socket.h"
#include "map.h"
#include "loader.h"
#include "bonuscontrol.h"


// Tank Scene
class TScene : public Loader
{
public:
	TScene() = default;
	TScene(std::vector<Unit> units,
		BattleMap map,
          bonusControl bonuses) :
             units_(units), map_(map), bonuses_(bonuses){};

    int load(Socket socket) override;
    int send(Socket socket) override;

    std::vector<Unit> getUnits() const;
    void setUnits(std::vector<Unit> units);

	BattleMap getMap() const;
    void setMap(BattleMap map);

    bonusControl getBonusControl() const;
    void setBonusControl(bonusControl bonus);

    bool operator == (const TScene &other) const;

    bool operator != (const TScene &other) const;

private:
    std::vector<Unit> units_;
	BattleMap map_;
    bonusControl bonuses_;

    // Функция, проверяющая какие объекты с какими
    void intersect_objects();
};
#endif // SCENE_H
