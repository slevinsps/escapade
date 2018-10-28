#ifndef BONUS_H
#define BONUS_H

#define BONUS_NOBODY -1 // Не подобран игроками. Отображать на карте.

#define BONUS_TYPE_DAMAGE 1
#define BONUS_TYPE_HEALTH 2
#define BONUS_TYPE_SPEED 3

#define BONUS_DEFAULT_COEFFICIENT 20

#include "sceneobject.h"

class Bonus : public SceneObject
{
public:
    Bonus( int coefficient = BONUS_DEFAULT_COEFFICIENT,
           int type = BONUS_TYPE_DAMAGE,
           Position position = Position(),
           QImage texture = QImage("damage_type.png"),
           ) :
        SceneObject(position, texture),
        controlled_by_(BONUS_NOBODY),
        type_(type), coefficient_(coefficient){}
    Bonus operator = (const Bonus &v1);



protected:
    int controlled_by_;
    int type_;
    int coefficient_;
};

#endif // BONUS_H
