#ifndef BASE_VISUALIZER_H
#define BASE_VISUALIZER_H

#include "BattleGround.h"
#include "RoomLayer.h"

class BaseVisualizer
{
public:
	BaseVisualizer() : ground(BattleGround::offline(User("Escapade", 10), 6)) {
		control_tank = -1; 
		roomLayer_ = new RoomLayer(&(ground.get_room()), ground.scene_.getUnits());
		CCLOG("just compare %d - %d", roomLayer_->room_, &ground.room_);
	};
	//virtual ~BaseVisualizer();
  
	// Return i if user_units[i] exists, else  -1
	int get_user_unit(int i) {
		if (i < 0 || i >= ground.algorithms_.size()) {
			return -1;
		}
		return i;
	}

	void chooseTank(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
		if (i != -1)
			this->control_tank = get_user_unit(i);
	}

protected:
	int control_tank; // âûáîð òàíêà äëÿ óïðàâëåíèÿ ñ êëàâèàòóðû

	RoomLayer* roomLayer_;
	BattleGround ground;
};
#endif // BASE_VISUALIZER_H
