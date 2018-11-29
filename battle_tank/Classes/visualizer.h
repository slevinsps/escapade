#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "base_visualizer.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define TAG_PLAYERS_TABLE 20
#define TAG_PLAYERS_UNITS 30
#define TAG_BATTLE 40
#include "BodyParser.h"

class Visualizer : public BaseVisualizer, public cocos2d::Scene
{
private:
	cocos2d::Label* amount;

	float up; // скорость по оси Y
	float right; // скорость по оси X

	cocos2d::PhysicsWorld *sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) {
		sceneWorld = world; 
	};

	static std::map<cocos2d::EventKeyboard::KeyCode,
		std::chrono::high_resolution_clock::time_point> keys;
	cocos2d::Label * label;

	void updateTimer(float dt);

	cocos2d::ui::LoadingBar* loadingBar;
	cocos2d::Label* label_timer;


public:

	Visualizer() {}
	~Visualizer() {};

	Visualizer(const Visualizer &visualizer);

	Visualizer(Visualizer &&visualizer);

	Visualizer& operator = (const Visualizer &other);

	Visualizer& operator = (Visualizer &&other);

	bool operator == (const Visualizer &other) const;

	bool operator != (const Visualizer &other) const;

	void work();

	void add_players();

	// Functions for key listeners

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode code);

	// Functions necessary for the cocos2d::Scene

	// Launch game loop - https://www.gamefromscratch.com/post/2014/10/11/Cocos2d-x-Tutorial-Series-Game-loops-Updates-and-Action-Handling.aspx
	void update(float) override;

	// For ability to be called in AppDelegate
	static cocos2d::Scene* createScene();

	// Launch in init
	virtual bool init();

	// Last action before close
	void menuCloseCallback(cocos2d::Ref* pSender);

	// cocos2d prompt - implement the "static create()" method manually
	CREATE_FUNC(Visualizer);
};

#endif // VISUALIZER_H
