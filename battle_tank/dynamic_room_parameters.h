#ifndef DYNAMIC_ROOM_PARAMETERS_H
#define DYNAMIC_ROOM_PARAMETERS_H

class DimaicRoomParameters
{
public:
    DimaicRoomParameters();
    DimaicRoomParameters(int amount_of_players,
                 int status,
                 int amount_of_matches) :
                     cur_amount_of_players_(amount_of_players),\
                     status_(status),
                     cur_amount_of_matches(amount_of_matches){}
    virtual ~DimaicRoomParameters();

    int get_amount_of_players() const;
    void set_amount_of_players(int);

    int get_status() const;
    void set_status(int);

    int get_amount_of_matches() const;
    void set_amount_of_matches(int);


private:
    int cur_amount_of_players_;
    int status_;
    int cur_amount_of_matches;
};

#endif // DYNAMIC_ROOM_PARAMETERS_H
