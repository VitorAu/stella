#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "ecs/Scene.h"

class RenderSystem
{
  public:
    static void Update(Scene &scene);
};

#endif
