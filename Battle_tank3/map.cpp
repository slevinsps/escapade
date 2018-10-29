#include "map.h"

bool Map::operator == (const Map &other) const
{
    return this->filename_ == other.get_filename();
}

bool Map::operator != (const Map &other) const
{
    return this->filename_ != other.get_filename();
}

std::string Map::get_filename() const {
    return this->filename_;
}

void Map::set_filename(std::string filename){
    filename_ = filename;
}
