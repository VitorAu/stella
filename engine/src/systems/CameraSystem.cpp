#include "systems/CameraSystem.hpp"

#include "components/CCamera.hpp"
#include "components/CPosition.hpp"
#include "ecs/EntityManager.hpp"

void CameraSystem::Update(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CCamera *camera = scene.SceneCamera(*e);

        if (!camera) continue;
        if (camera->m_target == 0) continue;

        const EntityPointer &target = scene.SceneEntity(camera->m_target);
        if (!target) continue;

        CPosition *position = scene.ScenePosition(*target);
        CRender *render = scene.SceneRender(*target);
        if (!position || !render) continue;

        camera->m_camera.target = {position->m_position.x + render->m_srcRect.width * render->m_scale / 2.0f,
                                   position->m_position.y + render->m_srcRect.height * render->m_scale / 2.0f};
    }
}
