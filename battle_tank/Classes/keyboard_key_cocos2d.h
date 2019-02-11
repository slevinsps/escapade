#include "cocos2d.h"
#include "keyboard_key.h"

class KeyboardKeyCocos2d : public KeyboardKey, public cocos2d::EventKeyboard {
 public:
  KeyboardKeyCocos2d(cocos2d::EventKeyboard::KeyCode key_code, Event* event)
      : cocos2d::EventKeyboard(key_code, event), key_code_(key_code) {}

  bool IsKeyNumber() override {
    return ((key_code_ >= EventKeyboard::KeyCode::KEY_1) &&
            (key_code_ <= EventKeyboard::KeyCode::KEY_9));
  };

 private:
  cocos2d::EventKeyboard::KeyCode key_code_;
};