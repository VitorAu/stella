#include "ecs/Scene.hpp"

#include "components/CDebug.hpp"
#include "systems/CameraSystem.hpp"
#include "systems/DebugSystem.hpp"
#include "systems/InputSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/PhysicsSystem.hpp"
#include "systems/RenderSystem.hpp"

Scene::Scene() = default;

Scene::~Scene() = default;

EntityPointer Scene::SceneAddEntity(const std::string &tag)
{
    auto e = m_sceneEntities.CreateEntity(tag);
    return e;
}

const EntityPointer Scene::SceneEntity(const std::size_t id)
{
    return m_sceneEntities.Entity(id);
}

const EntityVector &Scene::SceneEntities()
{
    return m_sceneEntities.Entities();
}

const EntityVector &Scene::SceneEntities(const std::string &tag)
{
    return m_sceneEntities.Entities(tag);
}

CInput *Scene::SceneInput(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneInputs.find(eId);
    return it != m_sceneInputs.end() ? &it->second : nullptr;
}

CController *Scene::SceneController(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneControllers.find(eId);
    return it != m_sceneControllers.end() ? &it->second : nullptr;
}

CPosition *Scene::ScenePosition(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_scenePositions.find(eId);
    return it != m_scenePositions.end() ? &it->second : nullptr;
}

CRigidBody *Scene::SceneRigidBody(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneRigidBodies.find(eId);
    return it != m_sceneRigidBodies.end() ? &it->second : nullptr;
}

CRender *Scene::SceneRender(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneRenders.find(eId);
    return it != m_sceneRenders.end() ? &it->second : nullptr;
}

CCamera *Scene::SceneCamera(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneCameras.find(eId);
    return it != m_sceneCameras.end() ? &it->second : nullptr;
}

CDebug *Scene::SceneDebug(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneDebugs.find(eId);
    return it != m_sceneDebugs.end() ? &it->second : nullptr;
}

void Scene::SceneAddInput(const Entity &e, const CInput &c)
{
    std::size_t eId = e.Id();
    m_sceneInputs[eId] = c;
}

void Scene::SceneAddController(const Entity &e, const CController &c)
{
    std::size_t eId = e.Id();
    m_sceneControllers[eId] = c;
}

void Scene::SceneAddPosition(const Entity &e, const CPosition &c)
{
    std::size_t eId = e.Id();
    m_scenePositions[eId] = c;
}

void Scene::SceneAddRigidBody(const Entity &e, const CRigidBody &c)
{
    std::size_t eId = e.Id();
    m_sceneRigidBodies[eId] = c;
}

void Scene::SceneAddRender(const Entity &e, const CRender &c)
{
    std::size_t eId = e.Id();
    m_sceneRenders[eId] = c;
}

void Scene::SceneAddCamera(const Entity &e, const CCamera &c)
{
    std::size_t eId = e.Id();
    m_sceneCameras[eId] = c;
}

void Scene::SceneAddDebug(const Entity &e, const CDebug &c)
{
    std::size_t eId = e.Id();
    m_sceneDebugs[eId] = c;
}

CCamera *Scene::ActiveCamera()
{
    for (auto &e : m_sceneCameras)
    {
        return &e.second;
    }

    return nullptr;
}

void Scene::Update()
{
    float dt = GetFrameTime();
    m_sceneEntities.Update();

    InputSystem::Update(*this);
    MovementSystem::Update(*this);
    PhysicsSystem::Update(*this, dt);
    CameraSystem::Update(*this);
    RenderSystem::Update(*this);

    DebugSystem::Update(*this);
}
