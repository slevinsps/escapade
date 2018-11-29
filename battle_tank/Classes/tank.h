#ifndef TANK_H
#define TANK_H
#include "unit.h"
#include "weapon.h"
#include "body.h"

class Tank : public Unit
{
public:
	Tank(Player player,
		int team_id = 0,
		std::string name = "unknown tank",
		int type = LIGHT,
		Position position = Position(),
		std::string = "circle");
    Weapon& get_weapon();
    Body& get_body();
	
	void move(float power, bool back) override;
	
	void rotate_body(float power, bool clockwise) override;
	
	void rotate_weapon(float power, bool clockwise) override;
	
	void fire(int shot) override;

	void setModel(int type) override;

    void set_position(Position pos) override;

	void center_weapon() override;

    void sinchronize() override;

private:
    Weapon weapon_;
    Body body_;

};

#endif // TANK_H
