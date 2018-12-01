#include "player.h"

Player::Player(User user, int team_id, int life) : team_(team_id),
						life_(1)
{
	this->IP_ = user.get_IP();
	this->name_ = user.get_name();
}

void Player::change_team_id(int id) {
	team_.set_id(id);
}

int Player::get_team_id() const {
	return team_.get_id();
}

void Player::increase_life() {
	life_++;
}

void Player::new_match() {
	life_ = 1;
}

int Player::get_life() const {
	return life_;
}


void Player::increase_deaths() {
    deaths_++;
	life_--;
}
