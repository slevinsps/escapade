#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map
{
public:
    Map(std::string filename = "map.txt");
    ~Map();

    std::string get_filename() const;
    void set_filename(std::string filename);

     bool operator == (const Map &other) const;

     bool operator != (const Map &other) const;
private:
    int load();

    std::string filename_;
};

#endif // MAP_H
