#include "scene.h"


std::vector<Tank>& TScene::getUnits() {
    return units_;
}
void TScene::setUnits(std::vector<Tank> units) {
    units_= units;
}

BattleMap& TScene::getMap() {
    return map_;
}
void TScene::setMap(BattleMap map) {
    map_ = map;
}

bonusControl& TScene::getBonusControl() {
    return bonuses_;
}
void TScene::setBonusControl(bonusControl bonuses) {
    bonuses_ = bonuses;
}

bool TScene::operator == (const TScene &other) const
{
    return this->units_ == other.units_;
}

bool TScene::operator != (const TScene &other) const
{
    return this->units_ != other.units_;
}
