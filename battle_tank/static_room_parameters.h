#ifndef STATIC_ROOM_PARAMETERS_H
#define STATIC_ROOM_PARAMETERS_H

class StaticRoomParameters
{
public:
    StaticRoomParameters(int max_amount_of_players,
                 int status,
                 int time_limit,
                 int time_start,
                 int max_amount_of_matches) :
                     max_amount_of_players_(max_amount_of_players),\
                     time_limit_(time_limit),
                     time_start_(time_start),
                     status_(status),
                     max_amount_of_matches_(max_amount_of_matches){}
    ~StaticRoomParameters();

    int get_max_of_players() const;
    void set_max_of_players(int max_amount_of_players);

    int get_time_limit() const;
    void set_time_limit(int);

    int get_time_start() const;
    void set_time_start(int);

    int get_max_of_matches() const;
    void set_max_of_matches(int);


private:
    int max_amount_of_players_;
    int time_limit_;
    int time_start_;
    int max_amount_of_matches_;
    int status_;
};
#endif // STATIC_ROOM_PARAMETERS_H
