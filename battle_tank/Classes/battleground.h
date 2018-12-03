#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H

#include <vector>

#include "scene.h"
#include "room.h"
#include "user_control_bundle.h"

class BattleGround
{
public:
    BattleGround(TScene& tscene,
                 Room room,
                 std::vector<UnitControl>& bundles);
    virtual ~BattleGround();

	TScene& get_scene();

    Room& get_room();
    void set_room(Room room);

    std::vector<UnitControl>& get_algorithms();

	static BattleGround offline(User user, int amount);

	// ���� ���� �������� �������. ���������� ��� �� ���� ����
	// �������� �����������, � ������� ��������. � ���� ��� �������� �����(scene_). ��� ��������� ������ ������ -
	// �� ����� � �����, �������� ���� ������ �������� getUnits(). ����, � ��� �� ����� ������ ������, ���� ������ �����
	// ���� ������ �������� ����. ������ ������ �����(��� ����, ������, �����, ����) ������ � ���� ���� sprite.
	// sprite ����� ����� ������������� ���� tag. �������� ������ ������ ������������� ������ ������ ����� ������� ���
	// ������������� ������ �����(������ � ������� ������). ���� ���� ����������, ��� ���������� � ������� add_players().
	// ��������� ���� ������������ �� ������ � �������� ������, �� � �� ���� ��������� cocos2d::Node, � ��� ������� �������
	// ������ �� ������ �������, � ������� + TAG_PLAYERS_UNITS(define ����������� � ������������ ����� �������������)
	// ����, ����� ���������������� ����, ���� �������� ��� ������� - a->getTag() - TAG_PLAYERS_UNITS. ��� �� � �������� 
	// ����, ������� ������� ����, �������� ������ ����� ���� ���� �������. ��� �� �������� ���������� ������ ����� �����������
	// ���������� ����(� ���� ��� �� ���, ��� � � ���� ��������� ����������� i-��� �����). ���, � ��� ���� ����, �������� ����
	// ������� ���� � �� ����� ����� ������. �������� ���������� ������� damage(int).
	void attack(int defender, int attacker) {
		int damage = scene_.getUnits()[attacker].get_weapon().get_damage();
		scene_.getUnits()[defender].damage(damage);
		room_.players_[defender].increase_damage_received(damage);
		room_.players_[attacker].increase_damage_done(damage);

		if (!scene_.getUnits()[defender].is_alive()) {
			scene_.make_died(scene_.getUnits()[defender]);
			scene_.getUnits()[defender].destroy();
			room_.players_[defender].increase_deaths();
			room_.players_[attacker].increase_kills();
		}
	}
	TScene scene_;
	Room room_;
	std::vector<UnitControl> algorithms_;
private:
	;
};
#endif // BATTLEGROUND_H
