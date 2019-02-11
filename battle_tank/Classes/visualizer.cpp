#include "visualizer.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include <thread>
/*
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
*/

// Íèæå êîêîñîâñêèå âåùè

USING_NS_CC;

Scene* Visualizer::createScene()
{
	// Ñîçäà¸ì ñöåíó ñ ôèçèêîé
	auto scene = Scene::createWithPhysics();
	// Óñòàíàâëèâàåì DEBUGDRAW_ALL, ÷òîáû ãðàíèöû âñåõ ôèçè÷åñêèõ îáúåêòîâ îáâîäèëèñü êðàñíîé ëèíèåé
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// Ñîçäà¸ì ñëîé
	auto layer = Visualizer::create();
	// è ïåðåäà¸ì â íåãî óêàçàòåëü íà ôèçè÷åñêèé ìèð
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	// Äîáàâëÿåì ñîçäàííûé ñëîé
	scene->addChild(layer);

	return scene;
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
std::mutex g_lock1;
bool Visualizer::operator!=(const Visualizer& other) const { return false; }
void Visualizer::work(int i) {
	g_lock1.lock();
	auto right = MoveBy::create(2, Vec2(600, 0));
	auto left = MoveBy::create(2, Vec2(-600, 0));
	while (ground.scene_.getUnits()[i].is_runnable()) {
		CCLOG("Coord 0 %d;", ground.scene_.getUnits()[i].sprite->getPositionY());
		//if (ground.scene_.getUnits()[i].sprite->numberOfRunningActions() == 0) {
			//if (ground.scene_.getUnits()[0].sprite->getPositionX() < 0) {
			//ground.scene_.getUnits()[0].rotate_body(90, 0);
			ground.scene_.getUnits()[i].move(50, false, 0);
			ground.scene_.getUnits()[i].fire(1);
			//Sleep(100);
			ground.scene_.getUnits()[i].rotate_body(40, 0);
		//}
		//Sleep(100);


	}
	g_lock1.unlock();
}



std::mutex g_lock11;
void Visualizer::work1(int i) {
	g_lock11.lock();
	auto right = MoveBy::create(2, Vec2(600, 0));
	auto left = MoveBy::create(2, Vec2(-600, 0));
	while (ground.scene_.getUnits()[i].is_runnable()) {
		CCLOG("Coord 1 %d;", ground.scene_.getUnits()[i].sprite->getPositionY());
		//if (ground.scene_.getUnits()[i].sprite->numberOfRunningActions() == 0) {
			//if (ground.scene_.getUnits()[0].sprite->getPositionX() < 0) {
			//ground.scene_.getUnits()[0].rotate_body(90, 0);
			ground.scene_.getUnits()[i].move(50, false, 0);
			ground.scene_.getUnits()[i].rotate_body(180, 0);
		//}
		//Sleep(100);
		
		
	}
	g_lock11.unlock();
	
}



void Visualizer::updateTimer(float dt)
{
	// Ïîëó÷àåòñÿ èç êîìíàòû. À ïîêà òàê.
	static seconds time = 10s;
	if (time <= 0s)
	{
		unschedule(schedule_selector(Visualizer::updateTimer));
		for (Unit& unit : ground.scene_.getUnits()) {
			unit.destroy();
		}
		/*
		auto myScene = Scene::create();

		// Ñìåíà âûöâåòàíèåì
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, myScene, Color3B(0, 255, 255)));

		// Êóâûðîê ïî X
		Director::getInstance()->replaceScene(TransitionFlipX::create(2, myScene));
		*/
	}
	time--;
	label_timer->setString(std::to_string(time.count()));
}

void Visualizer::add_players() {
	int unit_size = ground.scene_.getUnits().size();
	if (unit_size == 0) {
		amount = cocos2d::Label::createWithTTF("Нет игроков", "fonts/Marker Felt.ttf", 12);
	}
	else {
		control_tank = 0;
		amount = cocos2d::Label::createWithTTF("Игроков:"+
		std::to_string(unit_size),
		"fonts/Marker Felt.ttf", 12);

		int i = 0; // Óíèêàëüíûé èäåíòèôèêàòîð ëåæèì â òåãå, óäîáíî
		// Ïðîáëåìà ñ ññûëêàìè ïîïðàâëåíà
		for (Tank& unit : ground.scene_.getUnits()) {
			unit.set_position(Position(i * 100 + 50, 100));
			unit.get_body().get_forward_movement().set_pos(Position(i * 100 + 50, 100));
			std::vector<Node*> nodes;
			unit.SceneNodes(nodes);
			for (Node* node : nodes) {
				node->setTag(TAG_PLAYERS_UNITS + i);
				addChild(node, 0);
			}
			i++;
		}
	}
	//removeChildByTag(TAG_PLAYERS_TABLE);
	amount->setTag(TAG_PLAYERS_TABLE);
	amount->setPosition(Vec2(30, 280));
	addChild(amount);
	CCLOG("sooome %d %d", unit_size * roomLayer_->font_size, roomLayer_->font_size);
	roomLayer_->setPosition(Vec2(30, 270 - unit_size * roomLayer_->font_size)); //240
	addChild(roomLayer_);

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
	Ôèçèêà - https://habr.com/post/342478/
	*/

	//Ñîçäà¸ì ðàìêó ðàçìåðîì visibleSize, òî åñòü âî âåñü ýêðàí, ñ
	//ôèçè÷åñêèì ìàòåðèàëîì ïî óìîë÷àíèþ è òîëùèíîé ðàìêè 3 ïèêñåëÿ
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize,
		PHYSICSBODY_MATERIAL_DEFAULT, 7);
	// Ñîçäà¸ì íîâûé óçåë, òî åñòü îáúåêò ñöåíû
	auto edgeNode = Node::create();
	// Óñòàíàâëèâàåì íà ïîçèöèþ ïî öåíòðó ýêðàíà
	edgeNode->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 25);
	// Äîáàâëÿåì ê óçëó ôèçè÷åñêîå òåëî
	edgeNode->setPhysicsBody(edgeBody);

	//Äîáàâëÿåì óçåë ê íàøåé ñöåíå
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

	

	
	
	add_players();


	std::thread thread1(&Visualizer::work1, this, 1);
	thread1.detach();
	std::thread thread0(&Visualizer::work, this, 0);

	thread0.detach();


	auto eventListener = EventListenerKeyboard::create();

	// Äëÿ òîãî, ÷òîáû ìîæíî áûëî äåðæàòü êíîïêó - https://www.gamefromscratch.com/post/2014/10/07/Cocos2d-x-Tutorial-Series-Handling-the-Keyboard.aspx
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

	// Óñòàíîâêà öâåòà
	auto color = Color4B(1, 50, 32, 255);
	auto colorLayer = new cocos2d::LayerColor;
	colorLayer->initWithColor(color);
	addChild(colorLayer, -100);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Visualizer::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	CCLOG("SEEEEET");

	//contactListener->onContactBegin = CC_CALLBACK_1(TScene::onContactBegan, this);
	//this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	this->schedule(schedule_selector(Visualizer::updateTimer), 1.f);

	this->scheduleUpdate();
	return true;
}

bool Visualizer::onContactBegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	if ((a->getCategoryBitmask() == BITMASK_ALIVE_UNIT) &&
		(b->getCategoryBitmask() == BITMASK_BULLET)) {
		int index_defender = a->getNode()->getTag() - TAG_PLAYERS_UNITS;
	    int index_attacker = b->getNode()->getTag() - TAG_PLAYERS_UNITS;
		
		ground.attack(index_defender, index_attacker);
		roomLayer_->update_info(index_defender);
		roomLayer_->update_info(index_attacker);


	}
	else if ((a->getCategoryBitmask() == BITMASK_BULLET) &&
		(b->getCategoryBitmask() == BITMASK_ALIVE_UNIT)) {
		int index_defender = b->getNode()->getTag() - TAG_PLAYERS_UNITS;
		int index_attacker = a->getNode()->getTag() - TAG_PLAYERS_UNITS;
		
		ground.attack(index_defender, index_attacker);
		roomLayer_->update_info(index_defender);
		roomLayer_->update_info(index_attacker);

		CCLOG("damaged %d and compare %d - %d", ground.room_.players_[index_attacker].get_damage_done(),
			roomLayer_->room_->players_[index_attacker].get_damage_done(),
			roomLayer_->room_, &ground.room_);
	}
	else if (a->getCategoryBitmask() == BITMASK_ALIVE_UNIT &&
			 b->getCategoryBitmask() == BITMASK_ALIVE_UNIT) {
		//CCLOG("TANKS FOUND HAS OCCURED");
		;
	}

	CCLOG("NOOO %d and %d", a->getCategoryBitmask(), b->getCategoryBitmask());
	return true;
}

Visualizer::Visualizer(const Visualizer& visualizer) {}

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
			ground.scene_.getUnits()[control_tank].rotate_body(-5, 1);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_D)) {
			ground.scene_.getUnits()[control_tank].rotate_body(5, 1);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_Q)) {
			ground.scene_.getUnits()[control_tank].rotate_weapon(1, false);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_E)) {
			ground.scene_.getUnits()[control_tank].rotate_weapon(1, true);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_W)) {
			ground.scene_.getUnits()[control_tank].move(1, false, 1);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_S)) {
			ground.scene_.getUnits()[control_tank].move(1, true, 1);
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_C)) {
			ground.scene_.getUnits()[control_tank].center_weapon();
		}
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE)) {
			ground.scene_.getUnits()[control_tank].fire(1);
		}
	}
	//work1(1);
	for (int i = 0; i < ground.scene_.getUnits().size(); i++) {
		ground.scene_.getUnits()[i].sinchronize();
	}
}



void Visualizer::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	for (Unit& unit : ground.scene_.getUnits()) {
		unit.destroy();
	}
	Sleep(100);
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
