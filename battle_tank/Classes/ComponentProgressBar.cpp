#include "ComponentProgressBar.h"

ComponentProgressBar::ComponentProgressBar(Position pos, int max, std::string filename)
{
	max_ = curr_ = max;

	auto lay = Layer::create();

	loading_bar = cocos2d::ui::LoadingBar::create("res/" + filename + "_active.png");
	loading_bar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	loading_bar->setPercent(100);

	background = cocos2d::Sprite::create("res/" + filename + "_back.png");

	amount = cocos2d::Label::createWithTTF(std::to_string(max_), "fonts/Marker Arial.ttf", 8);
	amount->setPosition(cocos2d::Vec2(30, 0));

	loading_bar->setScale(0.2f);
	background->setScale(0.2f);

	addChild(amount, 3);
	addChild(loading_bar, 2);
	addChild(background, 1);
	setPosition(pos.toVec2());
}

void ComponentProgressBar::set_current(int current) {
	curr_ = current;
}
void ComponentProgressBar::set_max(int max) {
	max_ = max;
}
void ComponentProgressBar::set_position(Position pos) {
	this->setPosition(pos.toVec2());
}

ComponentProgressBar::ComponentProgressBar(const ComponentProgressBar & other) {
	curr_ = other.curr_;
	max_ = other.max_;
	loading_bar = other.loading_bar;
	background = other.background;
	amount = other.amount;
}

ComponentProgressBar::ComponentProgressBar(ComponentProgressBar && other) {
	curr_ = other.curr_;
	max_ = other.max_;
	loading_bar = std::move(other.loading_bar);
	background = std::move(other.background);
	amount = std::move(other.amount);
}

ComponentProgressBar & ComponentProgressBar::operator=(const ComponentProgressBar & other) {
	curr_ = other.curr_;
	max_ = other.max_;
	loading_bar = other.loading_bar;
	background = other.background;
	amount = other.amount;
	
	return *this;
}

ComponentProgressBar & ComponentProgressBar::operator=(ComponentProgressBar && other) {
	curr_ = other.curr_;
	max_ = other.max_;
	loading_bar = std::move(other.loading_bar);
	background = std::move(other.background);
	amount = std::move(other.amount);

	return *this;
}

ComponentProgressBar::~ComponentProgressBar()
{
}
