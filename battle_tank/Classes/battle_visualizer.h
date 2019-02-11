#ifndef BATTLE_VISUALIZER_H
#define BATTLE_VISUALIZER_H

#include "keyboard_key.h"

#include "BattleGround.h"
#include "RoomLayer.h"

const int kWrongKey = -1;
const int kNoControlledTank = -1;

class BattleVisualizer {
 public:
  BattleVisualizer()
      : ground(BattleGround::offline(User("Escapade", kStandartUserIP),
                                     kStandartPlayersAmount)) {
    control_tank = kNoControlledTank;
    roomLayer_ = new RoomLayer(&(ground.get_room()), ground.scene_.getUnits());
  };
  virtual ~BattleVisualizer();
  ;

  // Return i if user_units[i] exists, else  -1
  int get_user_unit(int i);

  void chooseTank(KeyboardKey& key);

 protected:
  int control_tank;

  RoomLayer* roomLayer_;
  BattleGround ground;
};
#endif  // BATTLE_VISUALIZER_H
