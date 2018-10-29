#ifndef VISUALIZER_H
#define VISUALIZER_H
#include "scene.h"
class Visualizer
{
public:
    Visualizer();
    Visualizer(  Scene& scene) :
                 scene_(scene){}
    virtual ~Visualizer();

    int update_scene();

private:
    Scene scene_;
};
#endif // VISUALIZER_H
