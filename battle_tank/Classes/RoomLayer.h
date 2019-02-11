#pragma once
#include "cocos2d.h"
#include "BattleGround.h"


class RoomLayer : public cocos2d::Layer
{
public:
	int font_size;

	RoomLayer() {}
	RoomLayer(const RoomLayer& other);

	RoomLayer& operator=(const RoomLayer& other);

	RoomLayer(Room *room, std::vector<Tank> units);

	void update_info(int i);

	Room *room_;

	~RoomLayer() {};
private:

	cocos2d::Label* table_header;
	std::vector<cocos2d::Label*> labels_player;
	std::vector<std::string> tanks_name;

	std::string int_to_string(int value, int length);

	std::string set_string_length(std::string str, int length);

	cocos2d::Label* create_player_label(Player player, std::string tank_name);

	void create_player_table();
};

