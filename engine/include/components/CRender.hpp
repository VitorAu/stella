#ifndef CRENDER_HPP
#define CRENDER_HPP

#include <raylib.h>

struct CRender
{
    Texture2D m_texture = {};
    Rectangle m_srcRect = {};
    Vector2 m_origin = {0.0f, 0.0f};
    Color m_color = WHITE;

    float m_rotation = 0.0f;
    float m_scale = 1.0f;
};

#endif
