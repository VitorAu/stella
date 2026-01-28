#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "ecs/Scene.h"

class PhysicsSystem
{
  public:
   static void Update(Scene &scene, float dt);
};

#endif
