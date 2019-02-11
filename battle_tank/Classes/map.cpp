#ifndef MAP_CPP
#define MAP_CPP

#include "map.h"

BattleMap::BattleMap(std::string filename) : filename_(filename){};
BattleMap::~BattleMap(){}

std::string BattleMap::get_filename() const {
    return filename_;
}

void BattleMap::set_filename(std::string filename) {
    filename_ = filename;
}

bool BattleMap::operator == (const BattleMap &other) const {
    return filename_ == other.get_filename();
}

bool BattleMap::operator != (const BattleMap &other) const {
    return filename_ != other.get_filename();
}

#endif // MAP_CPP
