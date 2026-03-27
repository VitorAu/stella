#include "systems/InputSystem.hpp"
#include "raylib.h"

void InputSystem::Update(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CInput *input = scene.SceneInput(*e);
        if(!input) continue;
  
        input->m_up = IsKeyDown(KEY_W);
        input->m_down = IsKeyDown(KEY_S);
        input->m_left = IsKeyDown(KEY_A);
        input->m_right = IsKeyDown(KEY_D);
    }
};
