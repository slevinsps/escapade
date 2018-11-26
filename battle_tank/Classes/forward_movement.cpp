#include "forward_movement.h"

ForwardMovement::ForwardMovement(int max_speed, int max_back_speed) : Movement(max_speed), max_back_speed_(max_back_speed){}
ForwardMovement::~ForwardMovement(){}

int ForwardMovement::get_max_back_speed() const {
    return max_back_speed_;
}

void ForwardMovement::set_max_back_speed(int max_back_speed) {
    max_back_speed_ = max_back_speed;
}
bool ForwardMovement::operator == (const ForwardMovement &other) {
    return (other.get_max_back_speed() == other.get_max_back_speed()) &&
            (get_max_speed() == other.get_max_speed()) &&
            (get_current_speed() == other.get_current_speed());
}
