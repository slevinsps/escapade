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


// Ниже кокосовские вещи

USING_NS_CC;

Scene* Visualizer::createScene()
{
	// Создаём сцену с физикой
	auto scene = Scene::createWithPhysics();
	// Устанавливаем DEBUGDRAW_ALL, чтобы границы всех физических объектов обводились красной линией
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// Создаём слой
	auto layer = Visualizer::create();
	// и передаём в него указатель на физический мир
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	// Добавляем созданный слой
	scene->addChild(layer);

	return scene;
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void Visualizer::work() {
	;
	/*
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
	*/

}

void Visualizer::updateTimer(float dt)
{
	// Получается из комнаты. А пока так.
	static seconds time = 60s;
	if (time <= 0s)
	{
		//this->scheduleOnce(schedule_selector(Scene::GoToScene), 0);

		unschedule(schedule_selector(Visualizer::updateTimer));
	}
	time--;
	label_timer->setString(std::to_string(time.count()));
}

void Visualizer::add_players() {
	
	if (ground.algorithms_.size() == 0) {
		amount = cocos2d::Label::createWithTTF("No players", "fonts/Marker Felt.ttf", 24);
	}
	else {
		control_tank = 0;
		amount = cocos2d::Label::createWithTTF("Players:"+
			std::to_string(ground.algorithms_.size()),
			"fonts/Marker Felt.ttf", 24);

		for (int i = 0; i < ground.algorithms_.size(); i++)
		{
			if (ground.scene_.getUnits()[i].unit_name) {

				//removeChildByTag(TAG_PLAYERS_UNITS);

				ground.scene_.getUnits()[i].set_position(Position(i * 100 + 50, 100));
				
				// Данные поступают не по ссылкам, поэтому на самом деле теги не ставятся
				// надо написать функцию set_tag в user_bundle, которая вызовет set_tag в
				// tank, которая поставит тег всем, кроме пуль. Пулям тег поставить должна пушка
				// Опять же это связано с тем, что нигде не возвращаются ссылки
				ground.scene_.getUnits()[i].get_body().sprite->setTag(TAG_PLAYERS_UNITS);
				ground.scene_.getUnits()[i].get_body().bar_->setTag(TAG_PLAYERS_UNITS);
				ground.scene_.getUnits()[i].get_weapon().sprite->setTag(TAG_PLAYERS_UNITS);
				ground.scene_.getUnits()[i].get_weapon().bar_->setTag(TAG_PLAYERS_UNITS);
				ground.scene_.getUnits()[i].unit_name->setTag(TAG_PLAYERS_UNITS);
				ground.scene_.getUnits()[i].sprite->setTag(TAG_PLAYERS_UNITS);

				int size = ground.scene_.getUnits()[i].get_weapon().get_max_amount_bullets();
				auto arr = ground.scene_.getUnits()[i].get_weapon().get_bullets();
				//CCLOG("LATE");
				for (int j = 0; j < size; j++) {
					
					if (arr[j].sprite) {
						arr[j].sprite->setTag(TAG_PLAYERS_UNITS);
						addChild(arr[j].sprite, 0);
					}
					else { CCLOG("nullptr found"); }
				}
				
				//auto tintBy = TintBy::create(2.0f, 120.0f, 232.0f, 254.0f);
				ground.scene_.getUnits()[i].sprite->runAction(TintBy::create(2.0f, rand() % 255, rand() % 255, rand() % 255));


				addChild(ground.scene_.getUnits()[i].sprite, 0);
				addChild(ground.scene_.getUnits()[i].unit_name);
				addChild(ground.scene_.getUnits()[i].get_body().sprite, 0);
				addChild(ground.scene_.getUnits()[i].get_body().bar_, 0);
				addChild(ground.scene_.getUnits()[i].get_weapon().sprite, 0);
				addChild(ground.scene_.getUnits()[i].get_weapon().bar_, 0);
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
#include "ui/CocosGUI.h"
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

	/*
	Физика - https://habr.com/post/342478/
	*/

	//Создаём рамку размером visibleSize, то есть во весь экран, с
	//физическим материалом по умолчанию и толщиной рамки 3 пикселя
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize,
		PHYSICSBODY_MATERIAL_DEFAULT, 7);
	// Создаём новый узел, то есть объект сцены
	auto edgeNode = Node::create();
	// Устанавливаем на позицию по центру экрана
	edgeNode->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 25);
	// Добавляем к узлу физическое тело
	edgeNode->setPhysicsBody(edgeBody);

	//Добавляем узел к нашей сцене
	this->addChild(edgeNode);

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

	//std::thread thread1(&Visualizer::work, this);

	//thread1.detach();

	
	
	add_players();

	auto eventListener = EventListenerKeyboard::create();

	// Для того, чтобы можно было держать кнопку - https://www.gamefromscratch.com/post/2014/10/07/Cocos2d-x-Tutorial-Series-Handling-the-Keyboard.aspx
	Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);

	eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		chooseTank(keyCode, event);
		if (keys.find(keyCode) == keys.end()) {
			keys[keyCode] = std::chrono::high_resolution_clock::now();
		}
	};
	eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		// remove the key.  std::map.erase() doesn't care if the key doesnt exist
		keys.erase(keyCode);
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

	label_timer = cocos2d::Label::create();
	label_timer->setPosition(visibleSize.width / 2, visibleSize.height);

	cocos2d::Sprite* sprite_timer  = cocos2d::Sprite::create("timer_frame.png");
	sprite_timer->setPosition(visibleSize.width / 2, visibleSize.height);

	sprite_timer->setTag(TAG_BATTLE);
	label_timer->setTag(TAG_BATTLE);
	label_timer->setScale(2);
	sprite_timer->setScale(3);
	this->addChild(label_timer, 5);
	this->addChild(sprite_timer, 4);

	label_timer->setString(std::to_string(60));

	// Установка цвета
	auto color = Color4B(1, 50, 32, 255);
	auto colorLayer = new cocos2d::LayerColor;
	colorLayer->initWithColor(color);
	addChild(colorLayer, -100);

	this->schedule(schedule_selector(Visualizer::updateTimer), 1.f);

	this->scheduleUpdate();
	return true;
}

bool Visualizer::isKeyPressed(EventKeyboard::KeyCode code) {
	// Check if the key is currently pressed by seeing it it's in the std::map keys
	// In retrospect, keys is a terrible name for a key/value paried datatype isnt it?
	if (keys.find(code) != keys.end())
		return true;
	return false;
}

void Visualizer::update(float delta) {
	Node::update(delta);
	if (control_tank >= 0) {
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_A)) {
			ground.scene_.getUnits()[control_tank].rotate_body(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_D)) {
			ground.scene_.getUnits()[control_tank].rotate_body(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_Q)) {
			ground.scene_.getUnits()[control_tank].rotate_weapon(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_E)) {
			ground.scene_.getUnits()[control_tank].rotate_weapon(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_W)) {
			ground.scene_.getUnits()[control_tank].move(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_S)) {
			ground.scene_.getUnits()[control_tank].move(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_C)) {
			ground.scene_.getUnits()[control_tank].center_weapon();
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE)) {
			ground.scene_.getUnits()[control_tank].fire(1);
		}
	}
	for (int i = 0; i < ground.scene_.getUnits().size(); i++) {
		ground.scene_.getUnits()[i].sinchronize();
	}
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

std::map<cocos2d::EventKeyboard::KeyCode,
	std::chrono::high_resolution_clock::time_point> Visualizer::keys;
