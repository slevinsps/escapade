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

float get_angle(float ang) {
	if (ang < 0) {
		while (ang < -360) {
			ang += 360;
		}
		if (ang < -180) {
			ang += 360;
		}
	}
	else {
		while (ang > 360) {
			ang -= 360;
		}
		if (ang > 180) {
			ang -= 360;
		}
	}
	return ang;
}

void Visualizer::moveTank(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
	Vec2 loc = body->getPosition();
	float change = 5.f;
	auto bo = body->getPhysicsBody();
	bo->setRotationEnable(true);
	float speed = 50.f;

	auto angle_ = get_angle(bo->getRotation());

	float ax = 40 * sinf(angle_/ 180.f * 3.14);
	float ay = 40 * cosf(angle_ / 180.f * 3.14);

	CCLOG("rotate %f and %f %f", angle_, ax, ay);
	auto startingSpeed_ = bo->getVelocity();
	

	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	case EventKeyboard::KeyCode::KEY_A:
		body->setRotation(body->getRotation() - change);
		//bo->setRotationOffset(bo->getRotationOffset() - 20.f);
		//bo->setAngularVelocity(20);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
		body->setRotation(body->getRotation() + change);
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		bo->setVelocity({ 0,0 });
		bo->resetForces();
		bo->setAngularVelocity({ 0 });
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	case EventKeyboard::KeyCode::KEY_W:
		bo->setVelocity(Vec2(ax, ay) * 10);
		//body->setRotation(body->getRotation - change);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	case EventKeyboard::KeyCode::KEY_S:
		bo->setVelocity(Vec2(-10 * cos(bo->getRotation()), -10 * sin(bo->getRotation())));
		//body->setRotation(body->getRotation - change);
		break;
	}

	if (keys.find(keyCode) == keys.end()) {
		keys[keyCode] = std::chrono::high_resolution_clock::now();
	}

	CCLOG("rotation:%d", int(bo->getRotation()));
}

void uu(int i);

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
	edgeNode->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 25);
	// Добавляем к узлу физическое тело
	edgeNode->setPhysicsBody(edgeBody);

	//Добавляем узел к нашей сцене
	this->addChild(edgeNode);

	// Создаём спрайт
	body = Sprite::create("tank_heavy_body.png");
	// Проверяем - существует ли json-файл
	CCLOG("-=-");
	if (BodyParser::getInstance()->parseJsonFile("tank_heavy_body.json"))
	{
		// Создаём физическое тело. Второй параметр - имя тела(не путать с именем файла), третий параметр - материал, с которым вы можете поиграться устанавливая различные значения.
		auto spriteBody = BodyParser::getInstance()->bodyFormJson(body, "tank_heavy_body", PhysicsMaterial(1.0f, 0.7f, 0.5f));
		if (spriteBody != nullptr)
		{
			// Устанавливаем тело для спрайта
			spriteBody->setGravityEnable(false);
			spriteBody->setLinearDamping(0.5);
			body->setPhysicsBody(spriteBody);
			CCLOG("WIN");
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

	// Для того, чтобы можно было держать кнопку - https://www.gamefromscratch.com/post/2014/10/07/Cocos2d-x-Tutorial-Series-Handling-the-Keyboard.aspx
	Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);

	eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keys.find(keyCode) == keys.end()) {
			keys[keyCode] = std::chrono::high_resolution_clock::now();
		}
	};
	eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		// remove the key.  std::map.erase() doesn't care if the key doesnt exist
		keys.erase(keyCode);
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

	auto handleControl = EventListenerKeyboard::create();

	auto bo = body->getPhysicsBody();
	float speed = 50.f;
	bo->setVelocity(Vec2(0, 50.f));

	labellll = cocos2d::Label::createWithSystemFont("Press the CTRL Key", "Arial", 32);
	labellll->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	addChild(labellll);

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
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_A)) {
		body->setRotation(body->getRotation() - 1);
		body->getPhysicsBody()->setAngularVelocity({ 0 });
	}
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_D)) {
		body->setRotation(body->getRotation() + 1);
		body->getPhysicsBody()->setAngularVelocity({ 0 });
	}
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_W)) {
		auto angle_ = get_angle(body->getRotation());

		float ax =  sinf(angle_ / 180.f * 3.14);
		float ay =  cosf(angle_ / 180.f * 3.14);
		/*
		float old_speed_x = body->getPhysicsBody()->getVelocity().x;
		float old_speed_y = body->getPhysicsBody()->getVelocity().y;

		if (old_speed_x < 1) {
			old_speed_x = 2;
		}

		if (old_speed_y < 1) {
			old_speed_y = 2;
		}

		ax *= old_speed_x;
		ay *= old_speed_y;
		*/
		body->getPhysicsBody()->resetForces();
		body->getPhysicsBody()->setVelocity(Vec2(ax, ay) * 20);

		CCLOG("rot!!!! %f", get_angle(body->getRotation()));
	}
	/*
	static int num = 1;
	//auto position = body->getPosition();
	//position.x -= num * 250 * delta;
	
	auto bo = body->getPhysicsBody();
	float speed = 500.f;
	if (body->getPositionX() < 0 - (body->getBoundingBox().size.width / 2)) {
		num *= -1;
		bo->setVelocity(bo->getVelocity().getNormalized() * speed);
		//position.x = this->getBoundingBox().getMaxX() + body->getBoundingBox().size.width / 2;
	}
	if (body->getPositionX() > 300) {
		num *= -1;
		//position.x = this->getBoundingBox().getMaxX() + body->getBoundingBox().size.width / 2;
	}
	//body->setPosition(position);
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

std::map<cocos2d::EventKeyboard::KeyCode,
	std::chrono::high_resolution_clock::time_point> Visualizer::keys;
