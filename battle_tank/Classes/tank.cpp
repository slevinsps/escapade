#include "tank.h"

Tank::Tank(Player player,
	int team_id, std::string name, int type,
	Position position,
	std::string texture) :
	Unit(player, team_id, name, type, 
		position, texture) {
	if (type == LIGHT) {
		weapon_ = Weapon(position, 10, 2, 0, 20,
			50, "light weapon",
			"tank_light_weapon.png");
		body_ = Body(position, 100, 203,
			203, 203, 0, "light body",
			"tank_light_body.png");
	} else {
		weapon_ = Weapon(position, 40, 20, 0, 4,
			20, "hard weapon",
			"tank_heavy_weapon.png");
		body_ = Body(position, 300, 53,
			23, 53, 0, "heavy body",
			"tank_heavy_body.png");
	}

}

void Tank::setModel(int type) {
	
	if (type == LIGHT) {
		weapon_ = Weapon(position_, 10, 2, 0, 20,
			50, "light weapon",
			"tank_light_weapon.png");
		body_ = Body(position_, 100, 203,
			203, 203, 0, "light body",
			"tank_light_body.png");
	}
	else {
		weapon_ = Weapon(position_, 40, 20, 0, 4,
			20, "hard weapon",
			"tank_heavy_weapon.png");
		body_ = Body(position_, 300, 53,
			23, 53, 0, "heavy body",
			"tank_heavy_body.png");
	}
}

Weapon& Tank::get_weapon() {
	return weapon_;
}
Body& Tank::get_body() {
	return body_;
}

void Tank::move(int speed) {}
void Tank::rotate(double angle) {}
void Tank::fire() {weapon_.fire();
}

#include "cocos2d.h"
void Tank::set_position(Position pos) {
	cocos2d::Vec2 vec = pos.toVec2();
	cocos2d::Vec2 vec2 = cocos2d::Vec2(vec.x, vec.y + 15);

	unit_name->setPosition(vec2);
	weapon_.sprite->setPosition(vec);
	body_.sprite->setPosition(vec);

	weapon_.position_ = position_;
	body_.position_ = position_;
}
