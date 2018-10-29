#include <QtCore/QCoreApplication>
#include <QtGui/QImage>
#include <iostream>

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class Position
{
public:
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    const bool operator == (const Position &v1, const Position &v2)
    {
        return (v1.x == v2.x) && (v1.y == v2.y);
    }

    int x, y;
};

class SceneObject
{
public:
    SceneObject(Position position = Position(),
                QImage texture = QImage("default.png")) :
        texture_(texture),
        texture_width_(texture.width()),
        texture_height_(texture.height()),
        position(position){}

    QImage getImage() const;
    int getImageWidth() const;
    int getImageHeigh() const;
    Position getPosition() const;

private:
    QImage texture_;
    int texture_width_;
    int texture_height_;
protected:
    void setPosition();
    Position position;

};

#endif // SCENEOBJECT_H
