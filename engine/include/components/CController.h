#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include "raylib.h"

enum struct CONTROLLER_MODE
{
    NONE,
    AI,
    PLAYER,
};

struct CController
{
    CONTROLLER_MODE m_controllerMode;
    Vector2 m_direction = {0.0f, 0.0f};
};

#endif
