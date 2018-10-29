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
    BattleGround(int time,
                 Scene& scene,
                 Room room,
                 std::vector<UserControlBundle>& bundles,
                 Visualizer& visualizer);
    virtual ~BattleGround();

    int get_time() const;
    void set_time(int);
    void add_bundle(UserControlBundle);

    int run_battle();
    int stop_battle();

    Room get_room() const;
    void set_room(Room room);

    std::vector<UserControlBundle> get_control_bundle() const;
    void set_control_bundle(std::vector<UserControlBundle> bundles);

    Visualizer get_vizualizer() const;
    void set_vizualizer(Visualizer& visualizer);

    void update_scene();

private:
    Visualizer visualizer_;
    int time_;
    Scene scene_;
    Room room_;
    std::vector<UserControlBundle> bundles_;
};
#endif // BATTLEGROUND_H
