#include "systems/PhysicsSystem.hpp"

#include <raymath.h>

void PhysicsSystem::Update(Scene &scene, float dt)
{
    for (const auto &e : scene.SceneEntities())
    {
        CController *controller = scene.SceneController(*e);
        CPosition *position = scene.ScenePosition(*e);
        CRigidBody *rigidBody = scene.SceneRigidBody(*e);
        if (!controller || !position || !rigidBody) continue;
        if (rigidBody->m_isStatic) continue;

        if (Vector2Length(controller->m_direction) > 0.0f)
        {
            rigidBody->m_acceleration = Vector2Scale(controller->m_direction, rigidBody->m_maxAcceleration);
            rigidBody->m_velocity = Vector2Add(rigidBody->m_velocity, Vector2Scale(rigidBody->m_acceleration, dt));
            rigidBody->m_velocity = Vector2ClampValue(rigidBody->m_velocity, 0.0f, rigidBody->m_maxVelocity);
        }
        else
        {
            float friction = 1.0f - rigidBody->m_friction * dt;
            rigidBody->m_velocity = Vector2Scale(rigidBody->m_velocity, friction);
            rigidBody->m_acceleration = {0.0f, 0.0f};
        }

        position->m_position = Vector2Add(position->m_position, Vector2Scale(rigidBody->m_velocity, dt));
    }
}
