#ifndef DYNAMIC_ROOM_PARAMETERS_H
#define DYNAMIC_ROOM_PARAMETERS_H

/*
����� �� �� ����� �������� ������ ��� � �����������
��� �������� �������� �� ����� �����
cur_amount_of_players_ - �� ������, ���� ����� ������ ������ � ���� �� ������� �� ����
cur_amount_of_matches - ���� �������

��� int, ����� � ������ ���� �������� ����� <0 � ���� ���� �����, ��� ��������� ������
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
