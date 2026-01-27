#include "systems/InputSystem.h"

#include "raylib.h"

void InputSystem::Update(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CInput *cInput = scene.SceneInput(*e);
        if (!cInput)
        {
            continue;
        }

        cInput->m_up = IsKeyDown(KEY_W);
        cInput->m_down = IsKeyDown(KEY_S);
        cInput->m_left = IsKeyDown(KEY_A);
        cInput->m_right = IsKeyDown(KEY_D);
    }
}
