#include "battle_visualizer.h"


BattleVisualizer::~BattleVisualizer() {}

// Return i if user_units[i] exists, else  -1
inline int BattleVisualizer::get_user_unit(int i) {
  if (i < 0 || i >= ground.algorithms_.size()) {
    return -1;
  }
  return i;
}

inline void BattleVisualizer::chooseTank(KeyboardKey& key) {
  int i = -1;
  switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_1:
      i = 0;
      break;
    case EventKeyboard::KeyCode::KEY_2:
      i = 1;
      break;
    case EventKeyboard::KeyCode::KEY_3:
      i = 2;
      break;
    case EventKeyboard::KeyCode::KEY_4:
      i = 3;
      break;
    case EventKeyboard::KeyCode::KEY_5:
      i = 4;
      break;
    case EventKeyboard::KeyCode::KEY_6:
      i = 5;
      break;
    case EventKeyboard::KeyCode::KEY_7:
      i = 6;
      break;
    case EventKeyboard::KeyCode::KEY_8:
      i = 7;
      break;
    case EventKeyboard::KeyCode::KEY_9:
      i = 8;
      break;
  }
  if (i != -1) this->control_tank = get_user_unit(i);
}
