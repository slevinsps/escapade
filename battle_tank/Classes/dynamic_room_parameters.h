#ifndef DYNAMIC_ROOM_PARAMETERS_H
#define DYNAMIC_ROOM_PARAMETERS_H

class DynamicRoomParameters
{
public:
    DynamicRoomParameters();
    ~DynamicRoomParameters();

    int get_amount_of_players() const;
    void set_amount_of_players(int);

    int get_status()  const;
    void set_status(int);

    int get_amount_of_matches() const;
    void set_amount_of_matches(int);


private:
    int cur_amount_of_players_;
    int status_;
    int cur_amount_of_matches;
};

#endif // DYNAMIC_ROOM_PARAMETERS_H
