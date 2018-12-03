#ifndef STATIC_ROOM_PARAMETERS_H
#define STATIC_ROOM_PARAMETERS_H

#include <chrono>

#define ERROR_WRONG_STATUS -3
#define STATUS_ERROR -4 // ���� ��������� ����(�������� ������� �������� ����������)
#define STATUS_FINISHED -2
#define STATUS_PREPARING -1
#define STATUS_ONGOING 0

using namespace std::chrono;
/*
�������� ����� ������ � �����������.
��� ����� ����������, ������� ��������������� �� ������� ��� ����� ���������
�����. ��� ������ ������������ � �����
*/
class StaticRoomParameters
{
public:
	StaticRoomParameters(size_t amount_of_players,
		seconds time_limit,
		size_t max_amount_of_matches);
    virtual ~StaticRoomParameters();

	// ���� ����� �������(��������� ��� �������)
	void prepare();

	// ���� ��������
	void start();

	// ���� ����������
	void finish();

	// ������� ��������� �����

	size_t players() const;

	seconds get_time_limit() const;

	steady_clock::time_point get_time_start(int &error) const;

	steady_clock::time_point get_time_end(int &error) const;

	size_t matches() const;

	static StaticRoomParameters default();

private:
	// ������������ ���-�� ������� � �������
	size_t max_amount_of_matches_;
	size_t max_amount_of_players_;

	// ����������������� ������
    seconds time_limit_;

	// ����� ������� � ��������� �����
	steady_clock::time_point time_start_;
	steady_clock::time_point time_end_;

	// ��������� �����
	int status_;
};

#endif // STATIC_ROOM_PARAMETERS_H
