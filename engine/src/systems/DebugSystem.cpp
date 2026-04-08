#include "systems/DebugSystem.hpp"

#include <raylib.h>
#include <string>

void DebugSystem::Update(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CDebug *debug = scene.SceneDebug(*e);
        CPosition *position = scene.ScenePosition(*e);
        CRigidBody *rigidBody = scene.SceneRigidBody(*e);
        CRender *render = scene.SceneRender(*e);
        CCamera *camera = scene.SceneCamera(*e);

        if (!debug) continue;
        if(!debug->m_enabled) continue;

        std::vector<std::pair<std::string, std::string>> debugLines = {};
        Rectangle panel = {};
        int yOffset = 0;

        if (!position) continue;

        debugLines.emplace_back("Entity Info", "");
        debugLines.emplace_back("Id: ", std::to_string(e->Id()));
        debugLines.emplace_back("Tag: ", e->Tag());
        debugLines.emplace_back("X pos: ", std::to_string(position->m_position.x));
        debugLines.emplace_back("Y pos: ", std::to_string(position->m_position.y));

        if (rigidBody)
        {
            debugLines.emplace_back("X vel: ", std::to_string(rigidBody->m_velocity.x));
            debugLines.emplace_back("Y vel: ", std::to_string(rigidBody->m_velocity.y));
            debugLines.emplace_back("X acc: ", std::to_string(rigidBody->m_acceleration.x));
            debugLines.emplace_back("Y acc: ", std::to_string(rigidBody->m_acceleration.y));
            debugLines.emplace_back("Max vel: ", std::to_string(rigidBody->m_maxVelocity));
            debugLines.emplace_back("Max acc: ", std::to_string(rigidBody->m_maxAcceleration));
            debugLines.emplace_back("Fric: ", std::to_string(rigidBody->m_friction));
            debugLines.emplace_back("Mass: ", std::to_string(rigidBody->m_mass));
            debugLines.emplace_back("Is static: ", std::to_string(rigidBody->m_isStatic));
        }

        if (render)
        {
            debugLines.emplace_back("Has texture: ", render->m_texture.id != 0 ? "True" : "False");
        }

        if (camera)
        {
            debugLines.emplace_back("Has camera: ", camera->m_target == e->Id() ? "True" : "False");
            debugLines.emplace_back("X camera pos: ", std::to_string(camera->m_camera.target.x));
            debugLines.emplace_back("Y camera pos: ", std::to_string(camera->m_camera.target.y));
            debugLines.emplace_back("Camera id target: ", std::to_string(camera->m_target));
        }

        for (auto &it : debugLines)
        {
            Vector2 size = MeasureTextEx(GetFontDefault(), it.second.c_str(), 15, 1);

            float lineWidth = MeasureText(it.first.c_str(), 15) + MeasureText(it.second.c_str(), 15);

            if (lineWidth >= panel.width) panel.width = lineWidth;
            panel.height += size.y;
        }

        panel.x = position->m_position.x;
        panel.y = position->m_position.y - 120.0f;

        DrawRectangleRec(panel, GRAY);
        for (auto &it : debugLines)
        {
            yOffset += 20;

            DrawText(it.first.c_str(), panel.x + 5, panel.y + yOffset, 15, BLACK);
            DrawText(it.second.c_str(), panel.x + MeasureText(it.first.c_str(), 15) + 10, panel.y + yOffset, 15, BLACK);
        }
    }
}
