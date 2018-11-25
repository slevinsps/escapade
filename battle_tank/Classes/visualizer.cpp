#include "visualizer.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include <thread>

bool Visualizer::operator == (const Visualizer &other) const
{
    return this->base_get_scene() == other.base_get_scene();
}

bool Visualizer::operator != (const Visualizer &other) const
{
    return this->base_get_scene() != other.base_get_scene();
}

Visualizer& Visualizer::operator = (const Visualizer &other) {
	this->set_scene(other.base_get_scene());
	return *this;
}

Visualizer& Visualizer::operator = (Visualizer &&other) {
	this->set_scene(other.base_get_scene());
	return *this;
}

Visualizer::Visualizer(const Visualizer &visualizer) {
	this->set_scene(visualizer.base_get_scene());
}

Visualizer::Visualizer(Visualizer &&visualizer) {
	this->set_scene(visualizer.base_get_scene());
}


// Ќиже кокосовские вещи

USING_NS_CC;

Scene* Visualizer::createScene()
{
	return Visualizer::create();
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void Visualizer::work() {
	;

	auto right = MoveBy::create(2, Vec2(600, 0));
	auto left = MoveBy::create(2, Vec2(-600, 0));

	while (1) {
		if (!this)
			return;
		if (this->body == nullptr)
			return;
		if (this->body->numberOfRunningActions() == 0) {
			if (this->body->getPositionX() < 0) {
				this->body->stopAllActions();
				this->body->runAction(MoveBy::create(2, Vec2(600, 0)));
			}
			else if (this->body->getPositionX() > 300) {
				this->body->stopAllActions();
				this->body->runAction(MoveBy::create(2, Vec2(-600, 0)));
			}
		}
		Sleep(100);
	}


}

void Visualizer::add_players() {
	if (user_units.size() == 0) {
		load_user_units();
	}
	
	if (user_units.size() == 0) {
		amount = cocos2d::Label::createWithTTF("No players", "fonts/Marker Felt.ttf", 24);
	}
	else {
		amount = cocos2d::Label::createWithTTF("Players:"+
			std::to_string(user_units.size()),
			"fonts/Marker Felt.ttf", 24);

		for (int i = 0; i < user_units.size(); i++)
		{
			if (user_units[i].tank_.unit_name) {

				//removeChildByTag(TAG_PLAYERS_UNITS);

				user_units[i].set_position(Position(i * 100 + 50, 100));
				
				user_units[i].tank_.get_body().sprite->setTag(TAG_PLAYERS_UNITS);
				user_units[i].tank_.get_weapon().sprite->setTag(TAG_PLAYERS_UNITS);
				user_units[i].tank_.unit_name->setTag(TAG_PLAYERS_UNITS);
				
				addChild(user_units[i].tank_.unit_name);
				addChild(user_units[i].tank_.get_body().sprite, 0);
				addChild(user_units[i].tank_.get_weapon().sprite, 0);
			} 
			//else {
			//	printf("err");
			//}
		}
	}
	//amount = cocos2d::Label::createWithTTF("Hello World:" + user_units.size(), "fonts/Marker Felt.ttf", 24);
	
	removeChildByTag(TAG_PLAYERS_TABLE);
	amount->setTag(TAG_PLAYERS_TABLE);
	amount->setPosition(Vec2(100, 250));
	addChild(amount);
}

// on "init" you need to initialize your instance
bool Visualizer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Visualizer::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label


	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"

	auto sprite = Sprite::create("HelloWorld.png");
	if (sprite == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}



	body = Sprite::create("tank_heavy_telo.png");
	body->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(body, 0);

	//heavy_body->setColor(Color3B(120, 120, 255));

	body->setPosition(Vec2(-100, 100));

	/*
	// —мещаем на 50 точек наверх и на 10 вправо, за две секунды:
	auto moveBy = MoveBy::create(5, Vec2(300, 300));
	heavy_body->runAction(moveBy);
	moveBy = MoveBy::create(5, Vec2(300, -200));
	heavy_body->runAction(moveBy);
	*/
	/*
	// создаем несколько действий
	auto moveBy = MoveBy::create(2, Vec2(300, 100));
	auto fadeTo = FadeTo::create(2.0f, 3.0f);
	auto scaleBy = ScaleBy::create(2.0f, 5.0f);

	// создаем Spawn
	auto mySpawn = Spawn::createWithTwoActions(scaleBy, fadeTo);

	// объедин€ем все в последовательность
	auto seq = Sequence::create(moveBy, mySpawn, moveBy, nullptr);

	// запускаем
	heavy_body->runAction(seq);
	*/

	//std::thread thread1(&Visualizer::work, this);

	//thread1.detach();
	
	add_players();

	return true;
}


void Visualizer::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

