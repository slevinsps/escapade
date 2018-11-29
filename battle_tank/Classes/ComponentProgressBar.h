#ifndef CPB_H
#define CPB_H

#include "cocos2d.h"
#include "sceneobject.h"
#include "ui/CocosGUI.h"

class ComponentProgressBar : public cocos2d::Layer
{
private:
	cocos2d::ui::LoadingBar* loading_bar;
	cocos2d::Sprite* background;
	cocos2d::Label* amount;

	int max_;
	int curr_;
public:
	ComponentProgressBar() {}
	ComponentProgressBar(Position pos, int max, std::string filename);

	void set_current(int current);
	void set_max(int max);
	void set_position(Position pos);

	ComponentProgressBar(const ComponentProgressBar & other);

	ComponentProgressBar(ComponentProgressBar && other);

	ComponentProgressBar & operator=(const ComponentProgressBar & other);

	ComponentProgressBar & operator=(ComponentProgressBar && other);

	~ComponentProgressBar();
};

#endif // CPB_H
