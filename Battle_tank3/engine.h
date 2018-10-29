#ifndef ENGINE_H
#define ENGINE_H

#include "component.h"
#include "forward_movement.h"

#define ENGINE_DEFAULT_SPEED 0
#define ENGINE_MAX_SPEED 100
#define ENGINE_MAX_BACKSPEED -20

class Engine : public Component
{
public:
    // Ожидается позиция юнита, поэтому она задается явно
    // Дальше идут необязательные параметры конкретной модели
    // Поскольку не планируется изменение картинки, она
    // стоит в конце
    Engine(Position _position,
           int max_speed = ENGINE_MAX_SPEED,
           int max_backspeed = ENGINE_MAX_BACKSPEED,
           std::string name = "default engine",
           QImage _texture = QImage("engine.png")) :
        Component(_position, _texture, name),
        movement(ForwardMovement(max_speed, max_backspeed)){}

    int get_speed() const;
    int get_max_speed() const;
    int get_max_backspeed() const;

    void applyBonus(Bonus bonus) override;

private:
    ForwardMovement movement;
};

#endif // ENGINE_H
