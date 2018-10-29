#include "bonuscontrol.h"

bonusControl::bonusControl(int max_size) : max_size_(max_size){
    create();
};

bonusControl::~bonusControl(){}

void bonusControl::create(){
    //for (size_t i = 0; i < max_size_; i++){
    //    bonuses.push_back
    //}
}

int bonusControl::remove_bonus(int index)
{
    return SUCCESS;
}

std::vector<Bonus> bonusControl::get_bonuses() const {
    return bonuses;
}

int bonusControl::get_max_size() const {
    return max_size_;
}

bool bonusControl::operator == (const bonusControl &other) const
{
    return this->get_bonuses() == other.get_bonuses() &&
            this->get_max_size() == other.get_max_size();
}

bool bonusControl::operator != (const bonusControl &other) const
{
    return this->get_bonuses() != other.get_bonuses() ||
            this->get_max_size() != other.get_max_size();
}
