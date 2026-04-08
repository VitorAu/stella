#ifndef SCENE_HPP
#define SCENE_HPP

#include "ecs/EntityManager.hpp"

#include "components/CController.hpp"
#include "components/CInput.hpp"
#include "components/CPosition.hpp"
#include "components/CRender.hpp"
#include "components/CRigidBody.hpp"
#include "components/CCamera.hpp"
#include "components/CDebug.hpp"

#include <cstddef>
#include <unordered_map>

template <class T> using EntityComponentMap = std::unordered_map<std::size_t, T>;

class Scene
{
  private:
    EntityManager m_sceneEntities;

    EntityComponentMap<CInput> m_sceneInputs;
    EntityComponentMap<CController> m_sceneControllers;
    EntityComponentMap<CPosition> m_scenePositions;
    EntityComponentMap<CRigidBody> m_sceneRigidBodies;
    EntityComponentMap<CRender> m_sceneRenders;
    EntityComponentMap<CCamera> m_sceneCameras;
    EntityComponentMap<CDebug> m_sceneDebugs;

  public:
    Scene();
    ~Scene();

    EntityPointer SceneAddEntity(const std::string &);

    const EntityPointer SceneEntity(std::size_t);
    const EntityVector &SceneEntities();
    const EntityVector &SceneEntities(const std::string &);

    CInput *SceneInput(const Entity &);
    CController *SceneController(const Entity &);
    CPosition *ScenePosition(const Entity &);
    CRigidBody *SceneRigidBody(const Entity &);
    CRender *SceneRender(const Entity &);
    CCamera *SceneCamera(const Entity &);
    CDebug *SceneDebug(const Entity &);

    void SceneAddInput(const Entity &, const CInput &);
    void SceneAddController(const Entity &, const CController &);
    void SceneAddPosition(const Entity &, const CPosition &);
    void SceneAddRigidBody(const Entity &, const CRigidBody &);
    void SceneAddRender(const Entity &, const CRender &);
    void SceneAddCamera(const Entity &, const CCamera &);
    void SceneAddDebug(const Entity&, const CDebug &);

    CCamera *ActiveCamera();

    void Update();
};

#endif // !SCENE_HPP
