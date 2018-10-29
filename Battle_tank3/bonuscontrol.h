#ifndef BONUSCONTROL_H
#define BONUSCONTROL_H

#include "bonus.h"
#include <vector>

#define SUCCESS 0
#define BONUSCONTROL_CANT_DELETE -1

#define DEFAULT_MAX_SIZE 10

class bonusControl
{
public:
    bonusControl(int max_size = DEFAULT_MAX_SIZE);
    ~bonusControl();

    std::vector<Bonus> get_bonuses() const;

    int get_max_size() const;

    int remove_bonus(int index);

    bool operator == (const bonusControl &other) const;

    bool operator != (const bonusControl &other) const;

private:
    std::vector<Bonus> bonuses;
    int max_size_;

    void create();
};

#endif // BONUSCONTROL_H
