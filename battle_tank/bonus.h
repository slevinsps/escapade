#ifndef BONUS_H
#define BONUS_H

#define BONUS_NOBODY -1 // Не подобран игроками. Отображать на карте.

#define BONUS_TYPE_DAMAGE 1
#define BONUS_TYPE_HEALTH 2
#define BONUS_TYPE_SPEED 3

#define BONUS_DEFAULT_COEFFICIENT 1.1

#include "unit.h"
#include "sceneobject.h"

class Bonus : public SceneObject
{
public:
    Bonus( Position _position = Position(),
           QImage _texture = QImage("damage_type.png"),
           int _type = BONUS_TYPE_DAMAGE,
           int _coefficient = BONUS_DEFAULT_COEFFICIENT) :
        SceneObject(_position, _texture),
        controlled_by(BONUS_NOBODY),
        type(_type), coefficient(_coefficient){}

    void apply_bonus(Unit &unit){
        controlled_by = unit.get_unit_id();
    }
protected:
    int controlled_by;
    int type;
    double coefficient;
};

#endif // BONUS_H
