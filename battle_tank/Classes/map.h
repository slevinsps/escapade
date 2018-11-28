#ifndef MAP_H
#define MAP_H

#include <iostream>

class BattleMap
{
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
