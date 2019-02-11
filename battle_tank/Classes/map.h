#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "sceneobject.h"

class BattleMap : public SceneObject {
public:
	BattleMap(std::string filename = "map.txt");
    ~BattleMap();

    std::string get_filename() const;
    void set_filename(std::string filename);

     bool operator == (const BattleMap &other) const;

     bool operator != (const BattleMap &other) const;
private:
    int load();

    std::string filename_;
};

#endif // MAP_H
