#include "systems/MovementSystem.hpp"

#include "components/CController.hpp"

void MovementSystem::Update(Scene &scene)
{
    for (const auto &e : scene.SceneEntities())
    {
        CController *controller = scene.SceneController(*e);
        CInput *input = scene.SceneInput(*e);
        if (!controller || !input) continue;

        float xDirection = float(input->m_right) - float(input->m_left);
        float yDirection = float(input->m_down) - float(input->m_up);
        Vector2 direction = Vector2(xDirection, yDirection);

        controller->m_direction = direction;
    }
}
