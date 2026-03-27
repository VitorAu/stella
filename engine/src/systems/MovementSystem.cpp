#include "systems/MovementSystem.hpp"

void MovementSystem::Update(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CController *controller = scene.SceneController(*e);
        CInput *input = scene.SceneInput(*e);

        if (!controller || !input) continue;

        float xDir = input->m_right - input->m_left;
        float yDir = input->m_up - input->m_down;
        Vector2 dir = Vector2(xDir, yDir);

        controller->m_direction = dir;
    }
}
