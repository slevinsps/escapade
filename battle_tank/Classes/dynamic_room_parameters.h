#ifndef DYNAMIC_ROOM_PARAMETERS_H
#define DYNAMIC_ROOM_PARAMETERS_H

/*
ќп€ть же не дайте названию ввести вас в заблуждение
Ёти значени€ мен€ютс€ во врем€ матча
cur_amount_of_players_ - на случай, если будет онлайн верси€ и кого то выкинет из игры
cur_amount_of_matches - итак пон€тно

тип int, чтобы в случае чего значени€ стали <0 и было €вно видно, что произошла ошибка
*/

class DynamicRoomParameters
{
public:
	DynamicRoomParameters(size_t players);
    ~DynamicRoomParameters();

	void start(size_t players);

	void new_match(size_t players);

	void kill();

	int players() const;

	int matchs() const;

private:
	int cur_amount_of_players_;
	int cur_amount_of_matches;
};

#endif // DYNAMIC_ROOM_PARAMETERS_H
