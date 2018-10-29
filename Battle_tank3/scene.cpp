#include "scene.h"

int Scene::load(Socket socket) {
    return 0;
}

int Scene::send(Socket socket) {
    return 0;
}

std::vector<Unit> Scene::getUnits() const {
    return units_;
}
void Scene::setUnits(std::vector<Unit> units) {
    units_= units;
}

Map Scene::getMap() const {
    return map_;
}
void Scene::setMap(Map map) {
    map_ = map;
}

bonusControl Scene::getBonusControl() const {
    return bonuses_;
}
void Scene::setBonusControl(bonusControl bonuses) {
    bonuses_ = bonuses;
}

bool Scene::operator == (const Scene &other) const
{
    return this->units_ == other.getUnits();
}

bool Scene::operator != (const Scene &other) const
{
    return this->units_ != other.getUnits();
}
