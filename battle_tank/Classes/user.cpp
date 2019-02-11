#include "user.h"

User::User(std::string name, int ip,
	int status, int is_ready) {
	name_ = name;
	IP_ = ip;
	status_ = status;
	is_ready_ = is_ready;
}

bool User::operator == (const User &other) const
{
    return IP_ == other.get_IP();
}

bool User::operator != (const User &other) const
{
    return IP_ == other.get_IP();
}

int User::get_IP() const {
    return IP_;
}

int User::set_IP(int IP) {
    if (IP < 0) {
        return USER_IP_MUST_BE_POSITIVE;
    }
    IP_ = IP;
    return SUCCESS;
}

int User::set_status(int status) {
    if (status >= STATUSES_MIN && status <= STATUSES_MAX) {
        status_ = status;
        return SUCCESS;
    }
    return USER_UNKNOWN_STATUS;
}

int User::get_status() const {
    return status_;
}

void User::set_ready(bool is_ready) {
    is_ready_ = is_ready;
}
bool User::get_ready() const {
    return is_ready_;
}

int User::set_name(std::string name) {
    if (name.empty()) {
        return USER_EMPTY_NAME;
    }
    name_ = name;
    return SUCCESS;
}
std::string User::get_name() const {
    return name_;
}

User::User() : is_ready_(false), status_(WAITING),
    IP_(0), name_("no name user"){}
