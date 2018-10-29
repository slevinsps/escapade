#ifndef BONUSCONTROL_H
#define BONUSCONTROL_H

#include "bonus.h"
#include <vector>

class bonusControl
{
public:
    bonusControl();
private:
    std::vector<Bonus> passive_bonuses;
    std::vector<Bonus> active_bonuses;
    int max_size;

    void update_bonuses_positions();
    void create_bonus();
};

#endif // BONUSCONTROL_H
