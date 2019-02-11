#ifndef SCENE_COCOS_H
#define SCENE_COCOS_H

#include <vector>

#include "scene.h"

// Tank Scene
class TSceneCocos : public TScene
{
public:
	// Временное решение, пока нет препятствий и бонусов

	TSceneCocos(std::vector<Tank> units) { 
		;
	}

	TSceneCocos() = default;

private:
    std::vector<Tank> units_;
	BattleMap* map_;
    bonusControl bonuses_;
};
#endif // SCENE_COCOS_H
