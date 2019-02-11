#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "RoomLayer.h"
#include "base_visualizer.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define TAG_PLAYERS_TABLE 20
#define TAG_PLAYERS_UNITS 30
#define TAG_BATTLE 40
#include "BodyParser.h"

#include "map_cocos.h"

class Visualizer : public BaseVisualizer, public cocos2d::Scene {
 private:
  // экспериментальный подход
  BattleMapCocos *map_;

  //
  cocos2d::Label *amount;

  cocos2d::PhysicsWorld *sceneWorld;

  void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };

  static std::map<cocos2d::EventKeyboard::KeyCode,
                  std::chrono::high_resolution_clock::time_point>
      keys;

  void updateTimer(float dt);

  cocos2d::Label *label_timer;

  bool onContactBegin(cocos2d::PhysicsContact &contact);

 public:
  Visualizer() {
    map_ = new BattleMapCocos("c");
    addChild(map_->GetNode()->get());
    server_->run();
    //std::thread thread1(&Server::run, *server_);
    // CCLOG("123aaa123");
    //thread1.detach();
  }
  Visualizer(Server *server) : BaseVisualizer(server) {
    // чтение карты тайлов
    // auto map = TMXTiledMap::create("TileMap.tmx");
    // addChild(map, 0, 99);  // с меткой "99"

    map_ = new BattleMapCocos("c");
    addChild(map_->GetNode()->get());
  }
  ~Visualizer(){};

  Visualizer(const Visualizer &visualizer);

  Visualizer(Visualizer &&visualizer);

  Visualizer &operator=(const Visualizer &other);

  Visualizer &operator=(Visualizer &&other);

  bool operator==(const Visualizer &other) const;

  bool operator!=(const Visualizer &other) const;

  void add_players();

  void AddGroup(std::vector<cocos2d::Node *>, int i);

  void synchronizeGroup(std::vector<cocos2d::Node *>, Vec2 position);

  void synchronizeAttackers(std::vector<cocos2d::Node *>, Weapon weapon);

  void kill(std::vector<cocos2d::Node *>, int id);

  // Functions for key listeners

  bool isKeyPressed(cocos2d::EventKeyboard::KeyCode code);

  // Functions necessary for the cocos2d::Scene

  // Launch game loop -
  // https://www.gamefromscratch.com/post/2014/10/11/Cocos2d-x-Tutorial-Series-Game-loops-Updates-and-Action-Handling.aspx
  void update(float) override;

  // For ability to be called in AppDelegate
  static cocos2d::Scene *createScene();

  // Launch in init
  virtual bool init();

  // Last action before close
  void menuCloseCallback(cocos2d::Ref *pSender);

  void LoadCreate(SceneObject *obj) override{

  };
  void LoadDestroy(SceneObject *obj) override{};

  void synchronize() override;

  // std::vector<std::vector<cocos2d::Node*>> all_nodes;

  std::vector < std::vector<ComponentProgressBar *>> bars;
  std::vector<cocos2d::Label*> names;

  // cocos2d prompt - implement the "static create()" method manually
  CREATE_FUNC(Visualizer);
};

#endif  // VISUALIZER_H
