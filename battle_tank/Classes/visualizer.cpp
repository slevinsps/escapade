#include "visualizer.h"
#include <iostream>
#include <thread>
#include "SimpleAudioEngine.h"
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

Scene* Visualizer::createScene() {
  // Ñîçäà¸ì ñöåíó ñ ôèçèêîé
  auto scene = Scene::createWithPhysics();
  // Óñòàíàâëèâàåì DEBUGDRAW_ALL, ÷òîáû ãðàíèöû âñåõ ôèçè÷åñêèõ îáúåêòîâ
  // îáâîäèëèñü êðàñíîé ëèíèåé
  // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

  // Ñîçäà¸ì ñëîé
  auto layer = Visualizer::create();
  // è ïåðåäà¸ì â íåãî óêàçàòåëü íà ôèçè÷åñêèé ìèð
  layer->SetPhysicsWorld(scene->getPhysicsWorld());

  // Äîáàâëÿåì ñîçäàííûé ñëîé
  scene->addChild(layer);

  return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename) {
  printf("Error while loading: %s\n", filename);
  printf(
      "Depending on how you compiled you might have to add 'Resources/' in "
      "front of filenames in HelloWorldScene.cpp\n");
}

void Visualizer::updateTimer(float dt) {
  // Ïîëó÷àåòñÿ èç êîìíàòû. À ïîêà òàê.
  static seconds time = 10s;
  if (time <= 0s) {
    unschedule(schedule_selector(Visualizer::updateTimer));
    for (Unit& unit : server_->ground.scene_.getUnits()) {
      unit.destroy();
    }
    /*
    auto myScene = Scene::create();
    // Ñìåíà âûöâåòàíèåì
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, myScene,
    Color3B(0, 255, 255)));
    // Êóâûðîê ïî X
    Director::getInstance()->replaceScene(TransitionFlipX::create(2, myScene));
    */
  }
  time--;
  if (label_timer == nullptr) {
    label_timer = cocos2d::Label::create();
    label_timer->setPosition(200, 100);

    label_timer->setTag(TAG_BATTLE);
    label_timer->setScale(2);

    // this->addChild(label_timer, 5);
  }
  // label_timer->setString(std::to_string(time.count()));
}

void Visualizer::AddGroup(std::vector<cocos2d::Node*> nodes, int i) {
  for (Node* node : nodes) {
    node->setTag(TAG_PLAYERS_UNITS + i);
    addChild(node);
  }
}

void Visualizer::add_players() {
  int unit_size = server_->ground.scene_.getUnits().size();
  if (unit_size == 0) {
    amount = cocos2d::Label::createWithTTF(TEXT_NO_PLAYERS, STANDARD_FONT,
                                           AMOUNT_OF_PLAYERS_SIZE);
  } else {
    control_tank = 0;
    amount = cocos2d::Label::createWithTTF(
        TEXT_HAVE_PLAYERS + std::to_string(unit_size), STANDARD_FONT,
        AMOUNT_OF_PLAYERS_SIZE);

    int i = 0;  
	std::vector<Tank> units = server_->ground.scene_.getUnits();

    for (Tank& unit : units) {

      AddGroup(server_->ground.scene_.collisions_[i], i);
      AddGroup(server_->ground.scene_.other_[i], i);
      AddGroup(server_->ground.scene_.attackers_[i], i);

      std::vector<ComponentProgressBar*> row;

      row.push_back(new ComponentProgressBar(
          unit.position_, unit.get_body().get_max_health(), HEALTH_FILENAME));
      addChild(row.back());
      row.push_back(new ComponentProgressBar(
          unit.position_, unit.get_weapon().GetMaxBulletAmount(),
          RECHARGE_FILENAME));
      addChild(row.back());

      bars.push_back(row);

      auto nickname_label = cocos2d::Label::createWithTTF(
          unit.get_name(), STANDARD_FONT,
          NICKNAME_SIZE);
      names.push_back(nickname_label);
      addChild(names.back());

      killed.push_back(false);

      i++;
    }
  }
  // removeChildByTag(TAG_PLAYERS_TABLE);
  amount->setTag(TAG_PLAYERS_TABLE);
  amount->setPosition(Vec2(30, 280));
  addChild(amount);

  roomLayer_->setPosition(
      Vec2(30, 270 - unit_size * roomLayer_->font_size));  // 240
  addChild(roomLayer_);
}
#include "ui/CocosGUI.h"
// on "init" you need to initialize your instance
bool Visualizer::init() {
  //////////////////////////////
  // 1. super init first
  if (!Scene::init()) {
    return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  /*
  Ôèçèêà - https://habr.com/post/342478/
  */

  //Ñîçäà¸ì ðàìêó ðàçìåðîì visibleSize, òî åñòü âî âåñü ýêðàí, ñ
  //ôèçè÷åñêèì ìàòåðèàëîì ïî óìîë÷àíèþ è òîëùèíîé ðàìêè 3 ïèêñåëÿ
  auto edgeBody =
      PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 7);
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
  auto closeItem =
      MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                            CC_CALLBACK_1(Visualizer::menuCloseCallback, this));

  if (closeItem == nullptr || closeItem->getContentSize().width <= 0 ||
      closeItem->getContentSize().height <= 0) {
    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
  } else {
    float x =
        origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(x, y));
  }

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  add_players();

  // std::thread thread1(&Visualizer::work1, this, 1);
  // thread1.detach();
  // std::thread thread0(&Visualizer::work, this, 0);

  // thread0.detach();

  auto eventListener = EventListenerKeyboard::create();

  // Äëÿ òîãî, ÷òîáû ìîæíî áûëî äåðæàòü êíîïêó -
  // https://www.gamefromscratch.com/post/2014/10/07/Cocos2d-x-Tutorial-Series-Handling-the-Keyboard.aspx
  Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);

  eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode,
                                    Event* event) {
    chooseTank(keyCode, event);
    if (keys.find(keyCode) == keys.end()) {
      keys[keyCode] = std::chrono::high_resolution_clock::now();
    }
  };
  eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode,
                                     Event* event) {
    // remove the key.  std::map.erase() doesn't care if the key doesnt exist
    keys.erase(keyCode);
  };
  this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,
                                                                 this);

  label_timer = cocos2d::Label::create();
  label_timer->setPosition(visibleSize.width / 2, visibleSize.height);

  cocos2d::Sprite* sprite_timer = cocos2d::Sprite::create("timer_frame.png");
  sprite_timer->setPosition(visibleSize.width / 2, visibleSize.height);

  sprite_timer->setTag(TAG_BATTLE);
  label_timer->setTag(TAG_BATTLE);
  // label_timer->setScale(2);
  sprite_timer->setScale(3);
  this->addChild(label_timer, 5);
  this->addChild(sprite_timer, 4);

  label_timer->setString(std::to_string(60));

  // Óñòàíîâêà öâåòà
  // auto color = Color4B(1, 50, 32, 255);
  // auto colorLayer = new cocos2d::LayerColor;
  // colorLayer->initWithColor(color);
  // addChild(colorLayer, -100);

  auto contactListener = EventListenerPhysicsContact::create();
  contactListener->onContactBegin =
      CC_CALLBACK_1(Visualizer::onContactBegin, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
      contactListener, this);

  // contactListener->onContactBegin = CC_CALLBACK_1(TScene::onContactBegan,
  // this);
  // this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener,
  // this);

  // this->schedule(schedule_selector(Visualizer::updateTimer), 1.f);
  // schedule(SEL_SCHEDULE(&Visualizer::updateTimer), 5);
  // CCScheduler::sharedScheduler()->scheduleSelector(
  //    schedule_selector(Visualizer::updateTimer), this, 0, false);

  this->scheduleUpdate();
  // this->schedule(schedule_selector(Visualizer::updateTimer), 1.f);
  return true;
}

bool Visualizer::onContactBegin(cocos2d::PhysicsContact& contact) {
  PhysicsBody* a = contact.getShapeA()->getBody();
  PhysicsBody* b = contact.getShapeB()->getBody();

  int index_defender = a->getNode()->getTag() - TAG_PLAYERS_UNITS;
  int index_attacker = b->getNode()->getTag() - TAG_PLAYERS_UNITS;

  if (index_defender == index_attacker) {
    return true;
  }

  if ((a->getCategoryBitmask() == BITMASK_ALIVE_UNIT) &&
      (b->getCategoryBitmask() == BITMASK_BULLET)) {
    server_->ground.attack(index_defender, index_attacker);
    roomLayer_->update_info(index_defender);
    roomLayer_->update_info(index_attacker);

  } else if ((a->getCategoryBitmask() == BITMASK_BULLET) &&
             (b->getCategoryBitmask() == BITMASK_ALIVE_UNIT)) {
    std::swap(index_defender, index_attacker);

    server_->ground.attack(index_defender, index_attacker);
    roomLayer_->update_info(index_defender);
    roomLayer_->update_info(index_attacker);

    CCLOG("%d attacked %d", index_defender, index_attacker);
  } else if (a->getCategoryBitmask() == BITMASK_ALIVE_UNIT &&
             b->getCategoryBitmask() == BITMASK_ALIVE_UNIT) {
    // CCLOG("TANKS FOUND HAS OCCURED");
    ;
  }

  CCLOG("NOOO %d and %d", a->getCategoryBitmask(), b->getCategoryBitmask());
  return true;
}

bool Visualizer::isKeyPressed(EventKeyboard::KeyCode code) {
  // Check if the key is currently pressed by seeing it it's in the std::map
  // keys In retrospect, keys is a terrible name for a key/value paried datatype
  // isnt it?
  if (keys.find(code) != keys.end()) return true;
  return false;
}

void Visualizer::synchronizeGroup(std::vector<cocos2d::Node*> nodes,
                                  Vec2 position) {
  for (int j = 0; j < nodes.size(); j++) {
    cocos2d::PhysicsBody* body = nodes[j]->getPhysicsBody();
    if (body != nullptr) {
      body->resetForces();
    }
    nodes[j]->setPosition(position);
  }
}

void Visualizer::synchronizeAttackers(std::vector<cocos2d::Node*> nodes,
                                      Weapon weapon) {
  for (int j = 0; j < nodes.size(); j++) {
    cocos2d::PhysicsBody* body = nodes[j]->getPhysicsBody();
    if (body != nullptr) {
      body->resetForces();
    }
    Bullet bullet = weapon.get_bullets()[j];

    // if (i == 3 && j == 3) {

    // if (bullet.forward_.IsActive()) CCLOG("i am so active");
    // if (bullet.IsFlying()) CCLOG("i am really active");
    //}
    // if (!bullet.IsFlying()) {
    //  CCLOG("IsFalse ");
    //}
    if (bullet.IsFlying()) {
      nodes[j]->setPosition(bullet.forward_.get_pos().toVec2());
      nodes[j]->setRotation(bullet.rotation_.get_current_angle());
    } else {
      nodes[j]->setPosition(Vec2(-100, -100));
    }
  }
}

void kill(std::vector<cocos2d::Node*>);

void Visualizer::synchronize() {
  for (int i = 0; i < server_->ground.scene_.getUnits().size(); i++) {
    Tank tank = server_->ground.scene_.getUnits()[i];
    Body body = tank.get_body();
    Weapon weapon = tank.get_weapon();

    Vec2 position = body.get_forward_movement().get_pos().toVec2();

    float x = body.get_forward_movement().get_pos().get_x();
    float y = body.get_forward_movement().get_pos().get_y();

    if (!tank.is_runnable()) {
      if (!killed[i]) {
        /*
                  for (int j = 0; j < ground.scene_.other_.size(); j++) {
          removeChild(ground.scene_.other_[i][j]);
          ground.scene_.other_[i][j] =
              SpriteSceneObjectCocos::Node(&tank, DIED_SCENEOBJECT);
          ground.scene_.other_[i][j]->setPosition(position);
          ground.scene_.other_[i][j]->setRotation(0);
          addChild(ground.scene_.other_[i][j]);
        }
                */
        killed[i] = true;
      }

      continue;
    }

    names[i]->setPosition(Vec2(x, y + 10));
    bars[i][0]->setPosition(Vec2(x, y - 12));
    bars[i][0]->set_current(tank.get_health());
    bars[i][1]->setPosition(Vec2(x, y - 10));
    bars[i][1]->set_current(tank.get_bullets_amount());
    this->synchronizeGroup(server_->ground.scene_.other_[i], position);
    this->synchronizeGroup(server_->ground.scene_.collisions_[i], position);
    this->synchronizeAttackers(server_->ground.scene_.attackers_[i], weapon);

    server_->ground.scene_.collisions_[i][0]->setRotation(body.get_angle());
    server_->ground.scene_.other_[i][0]->setRotation(body.get_angle() +
                                                     weapon.get_angle());
    server_->ground.scene_.other_[i][1]->setRotation(
        server_->ground.scene_.other_[i][1]->getRotation() + 1);
  }
}

void Visualizer::update(float delta) {
  Node::update(delta);
  // static int i = 0;
  // i++;
  // label_timer->setString(std::to_string(i));
  if (control_tank >= 0) {
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_A)) {
      server_->ground.scene_.getUnits()[control_tank].rotate_body(-10, 1);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_D)) {
      server_->ground.scene_.getUnits()[control_tank].rotate_body(10, 1);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_Q)) {
      server_->ground.scene_.getUnits()[control_tank].rotate_weapon(3, false);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_E)) {
      server_->ground.scene_.getUnits()[control_tank].rotate_weapon(3, true);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_W)) {
      server_->ground.scene_.getUnits()[control_tank].move(1, false, 1);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_S)) {
      server_->ground.scene_.getUnits()[control_tank].move(1, true, 1);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_C)) {
      server_->ground.scene_.getUnits()[control_tank].center_weapon();
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE)) {
      server_->ground.scene_.getUnits()[control_tank].fire(1);
    }
  }
  // work1(1);
  // Это действие в будущем уйдет из визуализатора
  for (int i = 0; i < server_->ground.scene_.getUnits().size(); i++) {
    server_->ground.scene_.getUnits()[i].synchronize();
  }
  synchronize();
}

void Visualizer::menuCloseCallback(Ref* pSender) {
  // Close the cocos2d-x game scene and quit the application
  int i = 0;
  for (Unit& unit : server_->ground.scene_.getUnits()) {
    unit.destroy();
    killed[i] = true;
    i++;
  }
  Sleep(500);
  Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif

  /*To navigate back to native iOS screen(if present) without quitting the
   * application  ,do not use Director::getInstance()->end() and exit(0) as
   * given above,instead trigger a custom event created in RootViewController.mm
   * as below*/

  // EventCustom customEndEvent("game_scene_close_event");
  //_eventDispatcher->dispatchEvent(&customEndEvent);
}

std::map<cocos2d::EventKeyboard::KeyCode,
         std::chrono::high_resolution_clock::time_point>
    Visualizer::keys;
