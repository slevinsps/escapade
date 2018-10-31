#ifndef MAP_CPP
#define MAP_CPP

#include "map.h"

Map::Map(std::string filename) : filename_(filename){};
Map::~Map(){}

std::string Map::get_filename() const {
    return filename_;
}

void Map::set_filename(std::string filename) {
    filename_ = filename;
}

bool Map::operator == (const Map &other) const {
    return filename_ == other.get_filename();
}

bool Map::operator != (const Map &other) const {
    return filename_ != other.get_filename();
}

#endif // MAP_CPP
