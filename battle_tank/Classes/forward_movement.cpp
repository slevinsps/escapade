#include "forward_movement.h"
#include <thread>

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


void ForwardMovement::move_to_distace(float distace, float speed, float angle) {
	g_move_tread.lock();
  //this->active = true;
	//this->active = true;
	if (speed < 0) {
		speed *= -1;
		distace *= -1;
	}
	float x, x_nach;
	x_nach = x = get_pos().get_x();
	float y, y_nach;
	y_nach = y = get_pos().get_y();
	float power = 2;
	auto angle_ = angle;

	float angle_radians = angle_ / 180.f * M_PI;

	float x_dist = x + distace * sinf(angle_radians);
	float y_dist = y + distace * cosf(angle_radians);
	//physic->setVelocity(cocos2d::Vec2(ax, ay));
	float L = 1;
	if (abs(x_dist - x) > abs(y_dist - y))
		L = abs(x_dist - x);
	else
		L = abs(y_dist - y);

	float sx = (x_dist - x) / L;
	float sy = (y_dist - y) / L;
        speed /= 10;
	for (int i = 1; i <= L / speed + 1; i++) {
		x += speed * sx;
		y += speed * sy;
		set_pos(Position(x, y));
		//this->active = true;
		//Sleep(100);
		//body_.set_speed(powf(ax * ax + ay * ay, 0.5f));
		Sleep(10);
	}
	//physic->setVelocity(cocos2d::Vec2(0, 0));
	//body_.set_speed(0);
	//sinchronize();
    this->active = false;
	g_move_tread.unlock();
        if (IsActive()) CCLOG("this->active");
   
}


void ForwardMovement::move(float distance, float speed, float angle, bool keyboard) {
	//sinchronize();

	std::thread thread1(&ForwardMovement::move_to_distace, this, distance, speed, angle);

	if (keyboard) {
          thread1.detach();
	}
	else {
		thread1.join();
	}
	
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

ForwardMovement::ForwardMovement(int max_speed, int max_back_speed)
    : max_back_speed_(max_back_speed) {
	max_speed_ = max_speed;
	current_speed_ = 0;
	this->stop = false;
    active = false;
}