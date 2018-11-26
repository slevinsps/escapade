
#include "user_control_bundle.h"

UserControlBundle::UserControlBundle(User user,
	UnitControl algorithm,
	Tank tank) :
    user_(user),
	algorithm_(algorithm),
	tank_(tank){

	if (user.get_name().size() < 1) {
		user.set_name("unknown user");
	}

	user_name = cocos2d::Label::createWithTTF(
		user.get_name(), "fonts/Marker Felt.ttf", 10);
}

UserControlBundle::~UserControlBundle(){}

void UserControlBundle::set_position(Position pos) {
	tank_.set_position(pos);
}

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
