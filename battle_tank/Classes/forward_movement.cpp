#include "forward_movement.h"

ForwardMovement::ForwardMovement(int max_speed, int max_back_speed) : max_back_speed_(max_back_speed){
	max_speed_ = max_speed;
	current_speed_ = 0;
}
ForwardMovement::~ForwardMovement(){}

bool ForwardMovement::operator == (const ForwardMovement &other) {
    return (getMaxSpeed() == other.getMaxSpeed()) &&
            (getMaxBackSpeed() == other.getMaxBackSpeed()) &&
            (getSpeed() == other.getSpeed());
}

int ForwardMovement::getSpeed() const {
	return current_speed_;
}
int ForwardMovement::getMaxSpeed() const {
	return max_speed_;
}
int ForwardMovement::getMaxBackSpeed() const {
	return max_back_speed_;
}

void ForwardMovement::setSpeed(int speed) {
	current_speed_ = speed;
}
void ForwardMovement::setMaxSpeed(int speed) {
	max_speed_ = speed;
}
void ForwardMovement::setMaxBackSpeed(int speed) {
	max_back_speed_ = speed;
}
