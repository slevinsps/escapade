#ifndef USER_H
#define USER_H

#include <string>

#include "unit_control.h"

enum statuses {
    DISSCONECTED = -1,
    OBSERVER = 0,
    PLAYER = 1};

class User
{
public:
    User() : isReady(false){}

    void setIP(int _IP);
    int getIP() const;

    void setStatus(int _status);
    int getStatus() const;

    void setName(std::string _name);
    std::string getName() const;

    void setController(UnitControl conntroller);

private:
    int IP;
    int status;
    UnitControl conntroller;
    bool isReady;
    std::string name;
};

#endif // USER_H
