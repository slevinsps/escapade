#include <QtCore/QCoreApplication>
#include <QtGui/QImage>
#include <iostream>

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

typedef struct Position
{
public:
    Position(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    int x, y;
} Position;

class SceneObject
{
public:
    SceneObject(Position _position = Position(),
                QImage _texture = QImage("default.png")) :
        texture(_texture),
        texture_width(_texture.width()), texture_height(_texture.height()),
        position(_position){}

    QImage getImage() const;
    int getImageWidth() const;
    int getImageHeigh() const;

    Position getPosition() const;
private:
    QImage texture;
    int texture_width;
    int texture_height;
protected:
    void setPosition();
    Position position;

};

#endif // SCENEOBJECT_H
