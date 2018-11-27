#include "scene.h"

int TScene::load(Socket socket) {
    return 0;
}

int TScene::send(Socket socket) {
    return 0;
}

std::vector<Unit> TScene::getUnits() const {
    return units_;
}
void TScene::setUnits(std::vector<Unit> units) {
    units_= units;
}

BattleMap TScene::getMap() const {
    return map_;
}
void TScene::setMap(BattleMap map) {
    map_ = map;
}

bonusControl TScene::getBonusControl() const {
    return bonuses_;
}
void TScene::setBonusControl(bonusControl bonuses) {
    bonuses_ = bonuses;
}

bool TScene::operator == (const TScene &other) const
{
    return this->units_ == other.getUnits();
}

bool TScene::operator != (const TScene &other) const
{
    return this->units_ != other.getUnits();
}
