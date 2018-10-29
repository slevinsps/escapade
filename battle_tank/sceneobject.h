#include <QtCore/QCoreApplication>
#include <QtGui/QImage>
#include <iostream>

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class Position
{
public:
    Position(int x = 0, int y = 0);

    bool operator == (const Position &other) const;

    bool operator != (const Position &other) const;

    int get_x() const;
    void set_x(int x);

    int get_y() const;
    void set_y(int y);
private:
    int x_, y_;
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
