#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <raylib.h>

class CRender
{
  public:
    Texture2D m_tex;
    Rectangle m_srcRec, m_destRec;
    Vector2 m_vecOrigin;
    int m_rotation = 0.0f;
};

class CTransform
{
  public:
    float m_x = 0.0f;
    float m_y = 0.0f;
};

#endif

