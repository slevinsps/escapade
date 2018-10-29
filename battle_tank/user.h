#ifndef USER_H
#define USER_H

#include <string>

enum statuses {
    WAITING = -2,
    DISSCONECTED = -1,
    OBSERVER = 0,
    PLAYER = 1};


#define STATUSES_MIN -2
#define STATUSES_MAX 1

#define SUCCESS 0
#define USER_IP_MUST_BE_POSITIVE -10
#define USER_UNKNOWN_STATUS -11
#define USER_EMPTY_NAME -12

class User
{
public:
    User();

    int set_IP(int IP);
    int get_IP() const;

    int set_status(int status);
    int get_status() const;

    void set_ready(bool ready);
    bool get_ready() const;

    int set_name(std::string _name);
    std::string get_name() const;

    bool operator == (const User &other) const;

    bool operator != (const User &other) const;

private:
    int IP_;
    int status_;
    bool is_ready_;
    std::string name_;
};

#endif // USER_H
