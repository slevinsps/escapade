#include "RoomLayer.h"

RoomLayer::RoomLayer(const RoomLayer& other) {
	room_ = other.room_;
	tanks_name = other.tanks_name;

	table_header = other.table_header;
	labels_player = other.labels_player;
}

RoomLayer& RoomLayer::operator=(const RoomLayer& other) {
	room_ = other.room_;
	tanks_name = other.tanks_name;

	table_header = other.table_header;
	labels_player = other.labels_player;

	return *this;
}


RoomLayer::RoomLayer(Room *room, std::vector<Tank> units) : room_(room) {
	for (Unit unit : units) {
		tanks_name.push_back(unit.get_name());
	}
	create_player_table();
}

void RoomLayer::update_info(int i) {
	std::string space = " ";
	std::string text = set_string_length(tanks_name[i], 11) + space +
		int_to_string(room_->players_[i].get_kills(), 4) + space +
		int_to_string(room_->players_[i].get_deaths(), 4) + space +
		int_to_string(room_->players_[i].get_damage_done(), 4);
	labels_player[i]->setString(text);
}

std::string RoomLayer::int_to_string(int value, int length) {
	return set_string_length(std::to_string(value), length);
}

std::string RoomLayer::set_string_length(std::string str, int length) {
	while (str.size() < length) {
		str += " ";
	}

	return str;
}

cocos2d::Label* RoomLayer::create_player_label(Player player, std::string tank_name) {
	auto label = cocos2d::Label::create("no name", "fonts/arial.ttf", font_size - 1);
	std::string space = " ";
	std::string text = set_string_length(tank_name, 11) + space +
		int_to_string(0, 4) + space +
		int_to_string(0, 4) + space + int_to_string(0, 4);
	label->setString(text);
	CCLOG("text is %s", text.c_str());
	return label;
}

void RoomLayer::create_player_table() {
	font_size = 8;

	//initWithColor(Color4B(50, 50, 50, 122));

	//table_header = cocos2d::Label::create("Имя танка  убил  погиб  нанес урона", "fonts/arial.ttf", font_size);
	// получил урона   тип танка   команда   Имя создателя
	//table_header->setPosition(Vec2(0, 0));
	//addChild(table_header, 4);

	std::vector<Player> players = room_->players_;
	for (int i = tanks_name.size() - 1; i >= 0; i--) {
		labels_player.push_back(create_player_label(players[i], tanks_name[i]));
		labels_player.back()->setPosition(Vec2(0, font_size * (i + 1)));
		addChild(labels_player.back(), 3);
	}
}