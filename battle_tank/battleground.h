#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H

#include <vector>
#include "scene.h"
#include "room.h"
#include "visualizer.h"
#include "user_control_bundle.h"

class BattleGround
{
public:
    BattleGround();
    BattleGround(int time,
                 Scene& scene,
                 Room& room,
                 std::vector<UserControlBundle>& bundles) :
                     time_(time), scene_(scene), room_(room), bundles_(bundles){}
    virtual ~BattleGround();

    int get_time() const;
    void set_time(int);
    int add_bundle(UserControlBundle);
    int run_battle();
    int stop_battle();

private:
    Visualizer visualizer;
    int time_;
    Scene scene_;
    Room room_;
    std::vector<UserControlBundle> bundles_;
};
#endif // BATTLEGROUND_H
