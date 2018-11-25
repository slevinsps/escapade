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
		std::string = "red_circle.png");
    Weapon& get_weapon();
    Body& get_body();
    void move(int speed) override;
    void rotate(double angle) override;
    void fire() override;

	void setModel(int type) override;

    void set_position(Position pos) override;

private:
    Weapon weapon_;
    Body body_;

};

#endif // TANK_H
