#ifndef CCONTROLLER_HPP
#define CCONTROLLER_HPP

#include <raylib.h>

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

#endif // !CCONTROLLER_HPP
