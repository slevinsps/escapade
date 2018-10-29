#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement
{
public:
    Movement(int max_speed, int current_speed = 0) : max_speed_(max_speed),
        current_speed_(current_speed){}
    ~Movement();

    int get_max_speed() const;
    int get_current_speed() const;

    void set_current_speed(int);
    void set_max_speed(int);

private:
    int max_speed_;
    int current_speed_;
};

#endif // MOVEMENT_H
