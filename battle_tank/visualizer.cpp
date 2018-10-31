#include "visualizer.h"

Visualizer::Visualizer(Scene scene) :
             scene_(scene){}

Visualizer::~Visualizer(){}

Scene Visualizer::get_scene() const {
    return scene_;
}

bool Visualizer::operator == (const Visualizer &other) const
{
    return this->scene_ == other.get_scene();
}

bool Visualizer::operator != (const Visualizer &other) const
{
    return this->scene_ != other.get_scene();
}
