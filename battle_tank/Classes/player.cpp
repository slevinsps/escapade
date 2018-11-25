#include "player.h"

Player::Player(User user) {
	this->IP_ = user.get_IP();
	this->name_ = user.get_name();
	this->deaths_ = 0;
	this->kills_ = 0;
}

Player::Player(int kills, int deaths) :
    kills_(kills), deaths_(deaths) {}

int Player::get_kills() const {
    return kills_;
}

void Player::increase_kills() {
    kills_ = kills_ + 1;
}

int Player::get_deaths() const {
    return deaths_;
}

void Player::increase_deaths() {
    deaths_ = deaths_ + 1;
}
