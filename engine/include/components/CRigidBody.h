#ifndef CRIGIDBODY_H
#define CRIGIDBODY_H

#include "raylib.h"

struct CRigidBody
{
    Vector2 m_velocity = {0.0f, 0.0f};
    Vector2 m_acceleration = {0.0f, 0.0f};

    float m_maxVelocity = 0.0f;
    float m_maxAcceleration = 0.0f;
    float m_friction = 0.0f;
    float m_mass = 1.0f;

    bool m_isStatic = false;
};

#endif
