#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H

#include <vector>

#include "scene.h"
#include "room.h"
#include "user_control_bundle.h"

class BattleGround
{
public:
    BattleGround(TScene& tscene,
                 Room room,
                 std::vector<UnitControl>& bundles);
    virtual ~BattleGround();

    //void add_bundle(UserControlBundle);

    Room get_room() const;
    void set_room(Room room);

    //std::vector<UserControlBundle> get_control_bundle() const;
    //void set_control_bundle(std::vector<UserControlBundle> bundles);

	static BattleGround offline(User user, int amount);

	TScene scene_;
	Room room_;
	std::vector<UnitControl> algorithms_;
private:
	;
};
#endif // BATTLEGROUND_H
