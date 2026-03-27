#include "systems/Systems.hpp"

void Systems::SRender(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CTransform *cTransform = scene.SceneTransform(*e);
        CRender *cRender = scene.SceneRender(*e);

        if (!cTransform || !cRender)
        {
            continue;
        }

        cRender->m_destRec.x = cTransform->m_x;
        cRender->m_destRec.y = cTransform->m_y;

        DrawTexturePro(cRender->m_tex, cRender->m_srcRec, cRender->m_destRec, cRender->m_vecOrigin, cRender->m_rotation,
                       WHITE);
    }
}

void Systems::STransform(Scene &scene, float dt)
{
    for (auto &e : scene.SceneEntities())
    {
        CTransform *cTransform = scene.SceneTransform(*e);
        CInput *cInput = scene.SceneInput(*e);

        if (!cTransform || !cInput)
        {
            continue;
        }

        float speed = 200.0f * dt;

        if (cInput->m_up)
        {
            cTransform->m_y -= speed;
        }
        if (cInput->m_down)
        {
            cTransform->m_y += speed;
        }
        if (cInput->m_left)
        {
            cTransform->m_x -= speed;
        }
        if (cInput->m_right)
        {
            cTransform->m_x += speed;
        }
    }
}

void Systems::SInput(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CInput *cInput = scene.SceneInput(*e);
        if (!cInput)
        {
            continue;
        }

        cInput->m_up = IsKeyDown(KEY_W);
        cInput->m_down = IsKeyDown(KEY_S);
        cInput->m_left = IsKeyDown(KEY_A);
        cInput->m_right = IsKeyDown(KEY_D);
    }
}
