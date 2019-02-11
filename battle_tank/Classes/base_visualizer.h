#ifndef BASE_VISUALIZER_H
#define BASE_VISUALIZER_H

#include "BattleGround.h"
#include "RoomLayer.h"
#include "map.h"

constexpr auto RECHARGE_FILENAME = "recharge";
constexpr auto HEALTH_FILENAME = "health";
constexpr auto TEXT_NO_PLAYERS = "no players";
constexpr auto TEXT_HAVE_PLAYERS = "players:";
constexpr auto STANDARD_FONT = "fonts/Marker Felt.ttf";
constexpr auto NICKNAME_SIZE = 10;
constexpr auto AMOUNT_OF_PLAYERS_SIZE = 12;

class Server {
 public:
  Server() : ground(BattleGround::offline(User("Escapade", 10), 6)) { ; };
  void init() {
    stop = false;
    int i = 0;
    for (Tank& unit : ground.scene_.getUnits()) {
      unit.get_body().get_forward_movement().set_pos(
          Position(i * 100 + 50, 100));
      unit.launch();
      mx.push_back(std::mutex());
      i++;
    }
    // some
  }

  std::mutex g_lock1;
  void work(int i) {
    g_lock1.lock();
    auto right = MoveBy::create(2, Vec2(600, 0));
    auto left = MoveBy::create(2, Vec2(-600, 0));
    while (ground.scene_.getUnits()[i].is_runnable()) {
      // CCLOG("Coord 0 %d;",
      // ground.scene_.getUnits()[i].sprite->getPositionY()); if
      // (ground.scene_.getUnits()[i].sprite->numberOfRunningActions() == 0) {
      // if (ground.scene_.getUnits()[0].sprite->getPositionX() < 0) {
      // ground.scene_.getUnits()[0].rotate_body(90, 0);
      ground.scene_.getUnits()[i].move(50, false, 0);
      ground.scene_.getUnits()[i].fire(1);
      // Sleep(100);
      ground.scene_.getUnits()[i].rotate_body(40, 0);
      //}
      Sleep(100);
    }
    g_lock1.unlock();
  }

  void start(int i, std::function<void(Unit&)> manage) { 
	mx[i].lock();
    while (ground.scene_.getUnits()[i].is_runnable()) {
       manage(ground.scene_.getUnits()[i]);
      Sleep(100);
    }
    mx[i].unlock();
  }

   void alg1(Unit& unit) {
    unit.move(50, false, 0);
    unit.rotate_body(180, 0);
  }

  std::mutex g_lock11;
  void work1(int i) {
    g_lock11.lock();
    while (ground.scene_.getUnits()[i].is_runnable()) {
      ground.scene_.getUnits()[i].move(50, false, 0);
      ground.scene_.getUnits()[i].rotate_body(180, 0);
      Sleep(100);
    }
    g_lock11.unlock();
  }

  void run() {
    std::thread thread1(&Server::mrun, this);
    // CCLOG("123aaa123");
    thread1.detach();
  }

  void mrun() {
    init();

	//UnitControl1 u1;
	//u

    std::thread thread1(&Server::work1, this, 1);

    std::thread thread0(&Server::work, this, 0);

    thread0.join();
    thread1.join();

    // while (!stop) {
    //  Sleep(2000);
    //}
  }

  Server& operator=(const Server& other) {
    // выполняем копирование значений
    ground = other.ground;
    stop = other.stop;

    // возвращаем текущий объект, чтобы мы могли связать в цепочку выполнение
    // нескольких операций присваивания
    return *this;
  }

  Server(const Server& other) : ground(other.ground) {
    ;
    stop = other.stop;
  }

  BattleGround ground;
  bool stop;

 private:
  std::vector<std::mutex> mx;
};

class BaseVisualizer {
 public:
  BaseVisualizer() {
    control_tank = -1;
    Server* server = new Server();
    server_ = server;
    roomLayer_ = new RoomLayer(&(server_->ground.get_room()),
                               server_->ground.scene_.getUnits());
    CCLOG("just compare %d - %d", roomLayer_->room_, &server_->ground.room_);
  }

  void create(Server* server) {
    server_ = server;
    control_tank = -1;
    roomLayer_ = new RoomLayer(&(server_->ground.get_room()),
                               server_->ground.scene_.getUnits());
  }

  BaseVisualizer(
      Server* server) {  // ground(BattleGround::offline(User("Escapade",
                         // 10), 6)) {
    server_ = server;
    control_tank = -1;
    roomLayer_ = new RoomLayer(&(server_->ground.get_room()),
                               server_->ground.scene_.getUnits());
    CCLOG("just compare %d - %d", roomLayer_->room_, &server_->ground.room_);
  };
  // virtual ~BaseVisualizer();

  // Return i if user_units[i] exists, else  -1
  int get_user_unit(int i) {
    if (i < 0 || i >= server_->ground.algorithms_.size()) {
      return -1;
    }
    return i;
  }

  void chooseTank(cocos2d::EventKeyboard::KeyCode keyCode,
                  cocos2d::Event* event) {
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
    if (i != -1) this->control_tank = get_user_unit(i);
  }

  virtual void LoadCreate(SceneObject* obj) = 0;
  virtual void LoadDestroy(SceneObject* obj) = 0;

  virtual void synchronize() = 0;

 protected:
  int control_tank;  // âûáîð òàíêà äëÿ óïðàâëåíèÿ ñ êëàâèàòóðû

  RoomLayer* roomLayer_;
  // BattleGround ground;
  Server* server_;
  std::vector<bool> killed;
};
#endif  // BASE_VISUALIZER_H
