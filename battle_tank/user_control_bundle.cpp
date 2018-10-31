
#include "user_control_bundle.h"

UserControlBundle::UserControlBundle(User user, UnitControl algorithm) :
    user_(user), algorithm_(algorithm){}

UserControlBundle::~UserControlBundle(){}

int UserControlBundle::load(Socket socket) {
    return 0;
}

int UserControlBundle::send(Socket socket) {
    return 0;
}

bool UserControlBundle::operator == (const UserControlBundle &other) const
{
    return this->getUser() == other.getUser();
}

bool UserControlBundle::operator != (const UserControlBundle &other) const
{
    return this->getUser() != other.getUser();
}

User UserControlBundle::getUser() const {
    return user_;
}

UnitControl UserControlBundle::getUnitControl() const {
    return algorithm_;
}
void UserControlBundle::setUnitControl(UnitControl UC) {
    algorithm_ = UC;
}
