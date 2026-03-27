#ifndef SYSTEMS_HPP
#define SYSTEMS_HPP

#include "ecs/Scene.hpp"

class Systems
{
  public:
    static void SRender(Scene &scene);
    static void STransform(Scene &scene, float dt);
    static void SInput(Scene &scene);
};

#endif

