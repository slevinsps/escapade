#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "player.h"
#include "sceneobject.h"

// Тип танка
enum types { LIGHT = 0, HARD = 1 };

// Тип выстрела
enum shot_types { ONE = 0, BURST = 1, ALL = 2 };

class Unit : public SpriteSceneObject {
 private:
  std::string name_;
  int type_;
  bool runnable;  // Флаг контроля

 public:

  // Явное указание игрока и команды
  Unit(std::string name = "unnamed unit", int type = LIGHT,
       Position _position = Position(), std::string texture_create = "circle",
       std::string texture_destroyed = "died135");

  ~Unit();

  // Обязательная функция запуска, ставит runnable в true
  // если runnable false поток управления прекращает работу
  void launch();

  // Есть ли управление
  bool is_runnable() const;

  // Вызывается при уничтожении юнита, ставит runnable в false
  void destroy();
  // Все сеттеры доступны только тогда, когда runnable = false

  std::string get_name() const;

  bool operator==(const Unit &other) const;

  bool operator!=(const Unit &other) const;

  void setName(std::string name);

  virtual void setModel(int type);

  // Устанавливает одинаковое положение(позицию и угол) для всех объектов юнита
  // В частности для корпуса: Корпус, Пушка, Ник, полоса здоровья, перезарядки и
  // т.д.
  virtual void synchronize(){};

  virtual void set_position(Position pos){};

  // power - процент от максимальной скорости
  // back - флаг движения назад
  virtual void move(float power, bool back, bool keyboard){};

  // power - процент от максимальной скорости
  // clockwise - флаг движения по часовой
  virtual void rotate_body(float angle, bool keyboard){};

  // power - процент от максимальной скорости
  // clockwise - флаг движения по часовой
  virtual void rotate_weapon(float power, bool clockwise) {}

  // Отцентрировать пушку
  virtual void center_weapon(){};

  // Тип выстрела - см. структуру shot_types
  virtual void fire(int shot){};

  // Нанести урон собственному танку
  virtual void damage(int damage){};

  // Проверить, жив ли танк
  virtual bool is_alive() { return false; };

  // Ниже классы для визуализатора

  // Массив объектов cocos2d::сцены(для добавления на сцену)
  virtual void SceneNodes(std::vector<SpriteSceneObject *> &nodes) {}

  // Получить компоненты юнита, участвующие в коллизиях
  virtual void ColiisionObjects(std::vector<SpriteSceneObject *> &) {}

  // Получить атакующие объекты юнита(для танков - пули)
  virtual void Attackers(std::vector<SpriteSceneObject *> &) {}

  // Получить оставшиеся объекты(пушки)
  virtual void OtherObjects(std::vector<SpriteSceneObject *> &) {}

  // Получить здоровье
  virtual int get_health() { return 0; };

  // Получить количество пуль
  virtual int get_bullets_amount() { return 0;}
};

#endif  // UNIT_H
