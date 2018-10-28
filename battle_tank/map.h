#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map
{
public:
    Map(std::string filename) : filename_(filename){};
    virtual ~Map();

    std::string get_filename() const;
    void set_filename(std::string filename);
private:
    std::string filename_;
};

#endif // MAP_H
