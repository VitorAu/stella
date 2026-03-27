#ifndef SCENE_HPP
#define SCENE_HPP

#include "EntityManager.hpp"
#include "components/CController.hpp"
#include "components/CInput.hpp"
#include "components/Components.hpp"

template <class T> using EntityComponentMap = std::unordered_map<std::size_t, T>;

class Scene
{
  private:
    EntityManager m_sceneEntities;

    EntityComponentMap<CInput> m_sceneInputs;
    EntityComponentMap<CController> m_sceneControllers;

    EntityComponentMap<CRender> m_sceneRenders;
    EntityComponentMap<CTransform> m_sceneTransforms;

  public:
    Scene();
    ~Scene();

    EntityPointer SceneAddEntity(const std::string &);

    const EntityVector &SceneEntities();
    const EntityVector &SceneEntities(std::string &);

    CInput *SceneInput(const Entity &);
    CController *SceneController(const Entity &);

    CRender *SceneRender(const Entity &);
    CTransform *SceneTransform(const Entity &);

    void SceneAddInput(const CInput &, const Entity &);
    void SceneAddController(const CController &, const Entity &);

    void SceneAddRender(const CRender &, const Entity &);
    void SceneAddTransform(const CTransform &, const Entity &);

    void Update();
};

#endif // !SCENE_HPP
