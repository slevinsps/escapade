#include "rotational_movement.h"

//RotateMovement::RotateMovement(int max_speed, int current_angle) :
 //   current_angle_(current_angle), Movement(max_speed){}

//RotateMovement::~RotateMovement(){}

int RotateMovement::get_current_angle() const {
    return current_angle_;
}

void RotateMovement::set_current_angle(int angle) {
    current_angle_ = angle;
}
bool RotateMovement::operator == (const RotateMovement &other) {
    return (other.get_current_angle() == other.get_current_angle()) &&
            (get_max_speed() == other.get_max_speed()) &&
            (get_current_speed() == other.get_current_speed());
}
