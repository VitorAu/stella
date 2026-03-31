#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include "ecs/Scene.hpp"

class PhysicsSystem
{
  public:
   static void Update(Scene &, float);
};

#endif // !PHYSICSSYSTEM_HPP
