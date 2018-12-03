#ifndef FORWARD_MOVEMENT_H
#define FORWARD_MOVEMENT_H
#include "movement.h"
#include "sceneobject.h"

class ForwardMovement : public Movement
{
public:
    ForwardMovement(int max_speed = 100, int max_back_speed = 50);

    ~ForwardMovement();

	ForwardMovement(const ForwardMovement& t) {
		this->max_back_speed_ = t.max_back_speed_;
		this->current_speed_ = t.current_speed_;
		this->max_speed_ = t.max_speed_;
		this->pos_object_ = t.pos_object_;
		this->stop = t.stop;
	}

	ForwardMovement& operator=(const ForwardMovement& t) {
		this->max_back_speed_ = t.max_back_speed_;
		this->current_speed_ = t.current_speed_;
		this->max_speed_ = t.max_speed_;
		this->pos_object_ = t.pos_object_;
		this->stop = t.stop;

		return *this;
	}

	int getSpeed() const;
	int getMaxSpeed() const;
	int getMaxBackSpeed() const;

	void setSpeed(int speed);
	void setMaxSpeed(int speed);
	void setMaxBackSpeed(int speed);
	void set_stop(bool a) { stop = a; }
	bool get_stop() { return stop;  }

	void set_pos(Position pos_object_v) { pos_object_ = pos_object_v; };
	Position& get_pos() { return pos_object_; };
	//void set_pos(Position p) { pos_ = p; );
	void move_to_distace(float distace, float speed, float angle);
	void move(float distance, float speed, float angle, bool keyboard);

  bool operator == (const ForwardMovement &v1);

private:
	std::mutex g_move_tread;
  int max_back_speed_;
	int current_speed_;
	Position pos_object_;

	// Íå çàäàåòñÿ const, ïîñêîëüêó ìîæåò ìåíÿòüñÿ áîíóñîì
	int max_speed_;
	bool stop;
};

#endif // FORWARD_MOVEMENT_H
