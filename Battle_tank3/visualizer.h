#ifndef VISUALIZER_H
#define VISUALIZER_H
#include "scene.h"
class Visualizer
{
public:
    Visualizer(Scene scene);
    ~Visualizer();

    int update_scene();

    Scene get_scene() const;

    bool operator == (const Visualizer &other) const;

    bool operator != (const Visualizer &other) const;

private:
    Scene scene_;
};
#endif // VISUALIZER_H
