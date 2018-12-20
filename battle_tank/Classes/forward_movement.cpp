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


void ForwardMovement::move_to_distace(float distace, float speed, RotateMovement& r) {
	//speed = 1;
	if (g_move_tread.try_lock() == false)
		return;
	if (speed < 0) {
		speed *= -1;
		distace *= -1;
	}
	float x, x_nach;
	x_nach = x = get_pos().get_x();
	float y, y_nach;
	y_nach = y = get_pos().get_y();
	float power = 2;
	auto angle_ = r.get_current_angle();

	float angle_radians = angle_ / 180.f * M_PI;

	float x_dist = x + distace * sinf(angle_radians);
	float y_dist = y + distace * cosf(angle_radians);
	float x_copy = x;
	float y_copy = y;
	float L = 1;
	if (abs(x_dist - x) > abs(y_dist - y))
		L = abs(x_dist - x);
	else
		L = abs(y_dist - y);

	float sx = (x_dist - x) / L;
	float sy = (y_dist - y) / L;
	for (int i = 1; i <= L / speed + 1; i++) {
		if (this->get_stop()) {
			g_move_tread.unlock();
			//this->set_stop(false);
			return;
		}


		x_copy += speed * sx;
		y_copy += speed * sy;
		set_pos(Position(x_copy, y_copy));
		//Sleep(100);
		//body_.set_speed(powf(ax * ax + ay * ay, 0.5f));
		Sleep(50);
	}
	

	//physic->setVelocity(cocos2d::Vec2(0, 0));
	//body_.set_speed(0);
	//sinchronize();
	g_move_tread.unlock();

}


void ForwardMovement::move(float distance, float speed, RotateMovement& r, bool keyboard) {
	//sinchronize();
	std::thread thread1(&ForwardMovement::move_to_distace, this, distance, speed, std::ref(r));
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

ForwardMovement::ForwardMovement(int max_speed, int max_back_speed) : max_back_speed_(max_back_speed) {
	max_speed_ = max_speed;
	current_speed_ = 0;
	this->stop = false;
}