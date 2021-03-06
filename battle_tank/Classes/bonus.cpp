#include "bonus.h"

Bonus::Bonus( int type,
       double coefficient,
        Position position,
        std::string texture) : SpriteSceneObjectCocos(position, texture, texture),
    type_(type), coefficient_(coefficient){}

void Bonus::set_type(int type) {
    type_ = type;
}

int Bonus::get_type() const {
    return type_;
}

void Bonus::set_coefficient(double coefficient) {
    coefficient_ = coefficient;
}

double Bonus::get_coefficient() const {
    return coefficient_;
}

bool Bonus::operator == (const Bonus &other) const {
    return (this->get_coefficient() == other.get_coefficient() &&
            this->get_type() == other.get_type());
}

bool Bonus::operator != (const Bonus &other) const {
    return this->coefficient_ != other.get_coefficient() ||
            this->type_ != other.get_type();
}
