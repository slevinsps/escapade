#ifndef BONUS_H
#define BONUS_H

#define BONUS_NOBODY -1 // Не подобран игроками. Отображать на карте.

#define BONUS_TYPE_DAMAGE 1
#define BONUS_TYPE_HEALTH 2
#define BONUS_TYPE_SPEED 3

#define BONUS_DEFAULT_COEFFICIENT 1.1

#include "sceneobject.h"

class Bonus : public SpriteSceneObjectCocos
{
public:
    Bonus( int type = BONUS_TYPE_DAMAGE,
           double coefficient = BONUS_DEFAULT_COEFFICIENT,
            Position position = Position(),
            std::string texture = "damage_type.png");

    void set_type(int Type);
    int get_type() const;

    void set_coefficient(double coefficient);
    double get_coefficient() const;

    bool operator == (const Bonus &other) const;

    bool operator != (const Bonus &other) const;
private:
    int type_;
    double coefficient_;
};

#endif // BONUS_H
