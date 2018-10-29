#include "player.h"

Player::Player(int kills, int deaths) : kills_(kills), deaths_(deaths) {}

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
