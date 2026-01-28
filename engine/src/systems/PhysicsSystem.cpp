#include "systems/PhysicsSystem.h"

#include "scribe.h"
#include "raymath.h"

void PhysicsSystem::Update(Scene &scene, float dt)
{
    for (const auto &e : scene.SceneEntities())
    {
        CController *controller = scene.SceneController(*e);
        CPosition *position = scene.ScenePosition(*e);
        CRigidBody *rigid_body = scene.SceneRigidBody(*e);
        if (!controller || !position || !rigid_body) continue;
        if (rigid_body->m_isStatic) continue;

        rigid_body->m_acceleration = Vector2Scale(controller->m_direction, rigid_body->m_maxAcceleration);
        rigid_body->m_velocity = Vector2Scale(rigid_body->m_acceleration, dt);

        position->m_position = Vector2Add(position->m_position, Vector2Scale(rigid_body->m_velocity, dt));

        // Scribe::Debug("Acceleration: {" ,rigid_body->m_acceleration.x, ", ", rigid_body->m_acceleration.y, "}");
        // Scribe::Debug("Velocity: {", rigid_body->m_velocity.x, ", ", rigid_body->m_velocity.y, "}");
        // Scribe::Debug("Position: {", position->m_position.x, ", ", position->m_position.y, "}");
    }
}
