//#include <QtCore/QCoreApplication>
//#include <QtGui/QImage>
#include <iostream>
#include "cocos2d.h"

#include "BodyParser.h"

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class Position {
 public:
  Position(int x = 0, int y = 0);
  ~Position();

  bool operator==(const Position& other) const;

  bool operator!=(const Position& other) const;

  Position& operator=(const Position& t) {
    this->x_ = t.get_x();
    this->y_ = t.get_y();
    return *this;
  }

  int get_x() const;
  void set_x(int x);

  int get_y() const;
  void set_y(int y);

  cocos2d::Vec2 toVec2();
  Position(cocos2d::Vec2 v);

 private:
  int x_, y_;
};

class SceneNode {
 public:
  SceneNode(){};
  // SceneNode(const SceneNode* node){};
  ~SceneNode(){};

  // virtual SceneNode* Get() = 0;
};

class SceneNodeCocos : public SceneNode {
 public:
  SceneNodeCocos() { value_ = nullptr; };
  SceneNodeCocos(cocos2d::Node* value) { set(value); };
  ~SceneNodeCocos() { ; };

  cocos2d::Node* get() { return value_; }
  void set(cocos2d::Node* value) { value_ = value; }

 private:
  cocos2d::Node* value_;
};

class SceneObject {
 public:
  SceneObject() { ; }

  virtual SceneNode* GetNode() { return nullptr; };
};

class SpriteSceneObject : public SceneObject {
 public:
  Position position_;

  SpriteSceneObject(SpriteSceneObject* obj) {
    position_ = obj->position_;
    filename_destroy_ = obj->filename_destroy_;
    filename_create_ = obj->filename_create_;
    physic_enable_ = obj->physic_enable_;
  };

  SpriteSceneObject(Position position = Position(),
                    std::string filename_create = "error",
                    std::string filename_destroy = "error",
                    bool physic = false) {
    position_ = position;
    filename_destroy_ = filename_destroy;
    filename_create_ = filename_create;
    physic_enable_ = physic;
  };

  virtual bool has_sprite() const { return false; };

  std::string get_filename_create() const { return filename_create_; }

  std::string get_filename_destroy() const { return filename_destroy_; }

  bool get_physic_enable() const { return physic_enable_; }

 protected:
  std::string filename_create_;
  std::string filename_destroy_;
  bool physic_enable_;
};

#define ALIVE_SCENEOBJECT 0
#define DIED_SCENEOBJECT -1

class SpriteSceneObjectCocos : public SpriteSceneObject {
 public:
  cocos2d::Sprite* sprite;
  
  static cocos2d::Node* Node(SpriteSceneObject* unit, int status) {
    SpriteSceneObjectCocos ssoc(unit);
    if (status == ALIVE_SCENEOBJECT) {
      ssoc.InitAsCreated(); 
	} else {
      ssoc.InitAsDestroyed();
	}
    return ssoc.GetNode()->get();
  }

  SpriteSceneObjectCocos(Position position = Position(),
                         std::string filename_create = "error",
                         std::string filename_destroy = "error",
                         bool physic = false)
      : SpriteSceneObject(position, filename_create, filename_destroy, physic) {
    Init(position, filename_create, physic);
  };

  SpriteSceneObjectCocos(SpriteSceneObject* spriteSceneObject)
      : SpriteSceneObject(spriteSceneObject) {}

  void InitAsCreated() {
    Init(this->position_, this->filename_create_, this->physic_enable_);
  }

  void InitAsDestroyed() {
    CCLOG("look at %s", filename_destroy_.c_str());
    Init(this->position_, this->filename_destroy_, this->physic_enable_);
  }

  SceneNodeCocos* GetNode() override { return new SceneNodeCocos(sprite); }

  bool has_sprite() const override;

 private:
  void Init(Position position, std::string filename, bool physic);
};

#endif  // SCENEOBJECT_H
