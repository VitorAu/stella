#ifndef SCENE_H
#define SCENE_H

#include "components/CController.h"
#include "components/CInput.h"
#include "ecs/EntityManager.h"

#include <cstddef>
#include <unordered_map>

template <class T> using EntityComponentMap = std::unordered_map<std::size_t, T>;

class Scene
{
  private:
    EntityManager m_sceneEntities;

    EntityComponentMap<CInput> m_sceneInputs;
    EntityComponentMap<CController> m_sceneControllers;

  public:
    Scene();
    ~Scene();

    EntityPointer SceneAddEntity(const std::string &tag);
    const EntityVector &SceneEntities();
    const EntityVector &SceneEntities(const std::string &tag);

    CInput *SceneInput(const Entity &e);
    CController *SceneController(const Entity &e);

    void SceneAddInput(const Entity &e, const CInput &c);
    void SceneAddController(const Entity &e, const CController &c);

    void Update();
};

#endif
