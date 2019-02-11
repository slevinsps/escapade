#ifndef MAP_COCOS_H
#define MAP_COCOS_H

#include <iostream>
#include "cocos2d.h"
#include "map.h"

class BattleMapCocos : public BattleMap {
 public:
  BattleMapCocos(std::string filename = "map.txt") {
    _tileMap = new cocos2d::CCTMXTiledMap();
    _tileMap->initWithTMXFile("TileMap.tmx");
    _background = _tileMap->layerNamed("Background");
  }
  ~BattleMapCocos(){};

  SceneNodeCocos* GetNode() override { return new SceneNodeCocos(_tileMap); }

 private:
  cocos2d::CCTMXTiledMap* _tileMap;
  cocos2d::CCTMXLayer* _background;
};

#endif  // MAP_COCOS_H
