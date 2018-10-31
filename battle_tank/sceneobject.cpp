#include "sceneobject.h"

int QImage::height(){return 0;}
int QImage::width(){return 0;}
QImage::QImage(const char*){};

SceneObject::SceneObject(Position position,
            QImage texture) :
    texture_(texture),
    position(position){}

Position::Position(int x, int y) : x_(x), y_(y){}

Position::~Position(){}

Position SceneObject::getPosition() const {
    return position;
}

int Position::get_x() const {
    return x_;
}
void Position::set_x(int x) {
    x_ = x;
}

int Position::get_y() const {
    return y_;
}
void Position::set_y(int y) {
    y_ = y;
}

bool Position::operator == (const Position &other) const
{
    return (this->get_x() == other.get_x());
}

bool Position::operator != (const Position &other) const
{
    return this->get_y() != other.get_y();
}
