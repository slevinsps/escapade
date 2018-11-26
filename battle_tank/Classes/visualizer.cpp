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
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

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

void Visualizer::chooseTank(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
	this->control_tank = get_user_unit(1);
}

void chooseTank(EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
	Vec2 loc = event->getCurrentTarget()->getPosition();
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	case EventKeyboard::KeyCode::KEY_A:
		event->getCurrentTarget()->setPosition(--loc.x, loc.y);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
		event->getCurrentTarget()->setPosition(++loc.x, loc.y);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	case EventKeyboard::KeyCode::KEY_W:
		event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	case EventKeyboard::KeyCode::KEY_S:
		event->getCurrentTarget()->setPosition(loc.x, --loc.y);
		break;
	}
}

#include "BodyParser.h"
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
		PHYSICSBODY_MATERIAL_DEFAULT, 3);
	// Создаём новый узел, то есть объект сцены
	auto edgeNode = Node::create();
	// Устанавливаем на позицию по центру экрана
	edgeNode->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	// Добавляем к узлу физическое тело
	edgeNode->setPhysicsBody(edgeBody);

	//Добавляем узел к нашей сцене
	this->addChild(edgeNode);

	// Создаём спрайт
	body = Sprite::create("tank_heavy_body.png");
	// Проверяем - существует ли json-файл
	if (BodyParser::getInstance()->parseJsonFile("tank_heavy_body.json"))
	{
		// Создаём физическое тело. Второй параметр - имя тела(не путать с именем файла), третий параметр - материал, с которым вы можете поиграться устанавливая различные значения.
		auto spriteBody = BodyParser::getInstance()->bodyFormJson(body, "tank_heavy_body", PhysicsMaterial(1.0f, 0.0f, 1.0f));
		if (spriteBody != nullptr)
		{
			// Устанавливаем тело для спрайта
			body->setPhysicsBody(spriteBody);
		}
		else
		{
			CCLOG("Object.cpp spriteBody is nullptr");
		}
	}
	else
	{
		CCLOG("JSON file not found");
	}

	// Установим спрайт в центре экрана
	body->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(body);

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
	/*
	body = Sprite::create("tank_heavy_body.png");
	body->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(body, 0);

	//heavy_body->setColor(Color3B(120, 120, 255));

	body->setPosition(Vec2(100, 100));
	*/
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



	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->setPosition(--loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->setPosition(++loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			event->getCurrentTarget()->setPosition(loc.x, --loc.y);
			break;
		}
	};
	eventListener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->setPosition(--loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->setPosition(++loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			event->getCurrentTarget()->setPosition(loc.x, --loc.y);
			break;
		}
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, body);

	auto handleControl = EventListenerKeyboard::create();

	this->scheduleUpdate();
	return true;
}

void Visualizer::update(float delta) {
	/*
	auto position = body->getPosition();
	position.x -= 250 * delta;
	if (position.x < 0 - (body->getBoundingBox().size.width / 2))
		position.x = this->getBoundingBox().getMaxX() + body->getBoundingBox().size.width / 2;
	body->setPosition(position);
	*/
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

