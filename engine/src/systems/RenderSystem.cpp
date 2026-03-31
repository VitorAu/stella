#include "systems/RenderSystem.hpp"

void RenderSystem::Update(Scene &scene)
{
    for (const auto &e : scene.SceneEntities())
    {
        CPosition *position = scene.ScenePosition(*e);
        CRender *render = scene.SceneRender(*e);
        if (!position || !render) continue;

        Rectangle destRect = {position->m_position.x, position->m_position.y, render->m_srcRect.width * render->m_scale,
                              render->m_srcRect.height * render->m_scale};

        DrawTexturePro(render->m_texture, render->m_srcRect, destRect, render->m_origin, render->m_rotation,
                       render->m_color);
    }
}