//#include <QtCore/QCoreApplication>
//#include <QtGui/QImage>
#include <iostream>

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class QImage {
public:
    QImage(const char*);

    int width();
    int height();
};

class Position
{
public:
    Position(int x = 0, int y = 0);
    ~Position();

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
                QImage texture = QImage("default.png"));

    QImage getImage() const;
    int getImageWidth() const;
    int getImageHeigh() const;
    Position getPosition() const;

private:
    QImage texture_;
protected:
    void setPosition();
    Position position;

};

#endif // SCENEOBJECT_H
