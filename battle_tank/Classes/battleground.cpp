#include "battleground.h"

BattleGround::BattleGround(int time,
             TScene& scene,
             Room room,
             std::vector<UserControlBundle>& bundles,
             Visualizer& visualizer) :
     time_(time), scene_(scene), room_(room),
     bundles_(bundles), visualizer_(visualizer) {}

void BattleGround::set_room(Room room) {
    room_ = room;
}

Room BattleGround::get_room()const {
    return room_;
}

void BattleGround::set_time(int time) {
    time_ = time;
}

int BattleGround::get_time()const {
    return time_;
}

void BattleGround::set_vizualizer(Visualizer& visualizer) {
    visualizer_ = visualizer;
}


Visualizer BattleGround::get_vizualizer() const {
    return visualizer_;
}

std::vector<UserControlBundle> BattleGround::get_control_bundle() const {
    return bundles_;
}

void BattleGround::set_control_bundle(std::vector<UserControlBundle> bundles) {
    bundles_ = bundles;
}

BattleGround::~BattleGround() {

}

void BattleGround::update_scene() {
    ;
}

int BattleGround::run_battle() {return 0;}
int BattleGround::stop_battle() {return 0;}
