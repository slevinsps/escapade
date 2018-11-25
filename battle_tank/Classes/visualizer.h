#ifndef VISUALIZER_H
#define VISUALIZER_H
#include "base_visualizer.h"
#include "cocos2d.h"

#define TAG_PLAYERS_TABLE 20
#define TAG_PLAYERS_UNITS 30

//public BaseVisualizer, 
class Visualizer : public BaseVisualizer, public cocos2d::Scene
{
private:
	cocos2d::Label* amount;
public:

	Visualizer() {}
	//~Visualizer() {};

	Visualizer(const Visualizer &visualizer);

	Visualizer(Visualizer &&visualizer);

	Visualizer& operator = (const Visualizer &other);

	Visualizer& operator = (Visualizer &&other);

	bool operator == (const Visualizer &other) const;

	bool operator != (const Visualizer &other) const;

	// Ниже кокосовские штуки

	cocos2d::Sprite *body;

	void work();

	static cocos2d::Scene* createScene();

	virtual bool init();

	void add_players();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Visualizer);
};

#endif // VISUALIZER_H
