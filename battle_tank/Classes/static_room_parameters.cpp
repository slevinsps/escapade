#include "static_room_parameters.h"

StaticRoomParameters::StaticRoomParameters(size_t amount_of_players,
	seconds time_limit,
	size_t max_amount_of_matches) :
	max_amount_of_players_(amount_of_players),
	time_limit_(time_limit),
	max_amount_of_matches_(max_amount_of_matches) 
{
	prepare();
}

void StaticRoomParameters::prepare() {
	status_ = STATUS_PREPARING;
}

void StaticRoomParameters::start() {
	status_ = STATUS_ONGOING;
	time_start_ = steady_clock::now();
}

void StaticRoomParameters::finish() {
	status_ = STATUS_FINISHED;
	time_end_ = steady_clock::now();
}

size_t StaticRoomParameters::players() const {
	return max_amount_of_players_;
};

seconds StaticRoomParameters::get_time_limit() const {
	return time_limit_;
}

steady_clock::time_point StaticRoomParameters::get_time_start(int &error) const {
	if (status_ != STATUS_PREPARING) {
		return time_start_;
	}
	error = ERROR_WRONG_STATUS;
	return steady_clock::now();
}

steady_clock::time_point StaticRoomParameters::get_time_end(int &error) const {
	if (status_ == STATUS_FINISHED) {
		return time_start_;
	}
	error = ERROR_WRONG_STATUS;
	return steady_clock::now();
}

size_t StaticRoomParameters::matches() const {
	return max_amount_of_matches_;
}

StaticRoomParameters StaticRoomParameters::default() {
	return StaticRoomParameters(4, 60s, 1);
}

StaticRoomParameters::~StaticRoomParameters(){}
