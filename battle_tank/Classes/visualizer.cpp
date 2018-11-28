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

void Visualizer::add_players() {
	if (user_units.size() == 0) {
		load_user_units();
	}
	
	if (user_units.size() == 0) {
		amount = cocos2d::Label::createWithTTF("No players", "fonts/Marker Felt.ttf", 24);
	}
	else {
		control_tank = 0;
		amount = cocos2d::Label::createWithTTF("Players:"+
			std::to_string(user_units.size()),
			"fonts/Marker Felt.ttf", 24);

		for (int i = 0; i < user_units.size(); i++)
		{
			if (user_units[i].tank_.unit_name) {

				//removeChildByTag(TAG_PLAYERS_UNITS);

				user_units[i].set_position(Position(i * 100 + 50, 100));
				
				// Данные поступают не по ссылкам, поэтому на самом деле теги не ставятся
				// надо написать функцию set_tag в user_bundle, которая вызовет set_tag в
				// tank, которая поставит тег всем, кроме пуль. Пулям тег поставить должна пушка
				// Опять же это связано с тем, что нигде не возвращаются ссылки
				user_units[i].tank_.get_body().sprite->setTag(TAG_PLAYERS_UNITS);
				user_units[i].tank_.get_weapon().sprite->setTag(TAG_PLAYERS_UNITS);
				user_units[i].tank_.unit_name->setTag(TAG_PLAYERS_UNITS);
				user_units[i].tank_.sprite->setTag(TAG_PLAYERS_UNITS);

				int size = user_units[i].tank_.get_weapon().get_max_amount_bullets();
				auto arr = user_units[i].tank_.get_weapon().get_bullets();
				//CCLOG("LATE");
				for (int j = 0; j < size; j++) {
					
					if (arr[j].sprite) {
						arr[j].sprite->setTag(TAG_PLAYERS_UNITS);
						addChild(arr[j].sprite, 0);
					}
					else { CCLOG("nullptr found"); }
				}
				
				//auto tintBy = TintBy::create(2.0f, 120.0f, 232.0f, 254.0f);
				user_units[i].tank_.sprite->runAction(TintBy::create(2.0f, rand() % 255, rand() % 255, rand() % 255));

				addChild(user_units[i].tank_.sprite, 0);
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


	/*
	// Смещаем на 50 точек наверх и на 10 вправо, за две секунды:
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

	// объединяем все в последовательность
	auto seq = Sequence::create(moveBy, mySpawn, moveBy, nullptr);

	// запускаем
	heavy_body->runAction(seq);
	*/

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

	loadingBar = cocos2d::ui::LoadingBar::create("LoadingBarFile.png");
	loadingBar->setName("LoadingBar");
	//loadingBar->loadTexture("cocosgui/sliderProgress.png");
	loadingBar->setPercent(50);
	loadingBar->setDirection(cocos2d::ui::LoadingBar::Direction::RIGHT);
	loadingBar->setPosition(Vec2(200, 200));
	this->addChild(loadingBar);
	this->schedule(schedule_selector(Visualizer::updateProgress), 0.025f);

	this->scheduleUpdate();
	return true;
}

void Visualizer::updateProgress(float dt)
{
	static int counter = 0;
	counter++;
	if (counter > 100)
	{
		//this->scheduleOnce(schedule_selector(Scene::GoToScene), 0);

		unschedule(schedule_selector(Visualizer::updateProgress));
	}
	loadingBar->setPercent(counter);
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
			this->user_units[control_tank].tank_.rotate_body(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_D)) {
			this->user_units[control_tank].tank_.rotate_body(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_Q)) {
			this->user_units[control_tank].tank_.rotate_weapon(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_E)) {
			this->user_units[control_tank].tank_.rotate_weapon(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_W)) {
			this->user_units[control_tank].tank_.move(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_S)) {
			this->user_units[control_tank].tank_.move(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE)) {
			this->user_units[control_tank].tank_.fire(1);
		}
	}
	for (int i = 0; i < user_units.size(); i++) {
		user_units[i].tank_.sinchronize();
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
