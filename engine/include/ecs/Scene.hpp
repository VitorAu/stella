#ifndef SCENE_HPP
#define SCENE_HPP

#include "EntityManager.hpp"
#include "components/Components.hpp"

template <class T> using EntityComponentMap = std::unordered_map<std::size_t, T>;

class Scene
{
  private:
    EntityManager m_sceneEntities;

    EntityComponentMap<CRender> m_sceneRenders;
    EntityComponentMap<CTransform> m_sceneTransforms;
    EntityComponentMap<CInput> m_sceneInputs;

  public:
    Scene();
    ~Scene();

    EntityPointer SceneAddEntity(const std::string &);

    const EntityVector &SceneEntities();
    const EntityVector &SceneEntities(std::string &);

    CRender *SceneRender(const Entity &);
    CTransform *SceneTransform(const Entity &);
    CInput *SceneInput(const Entity &);

    void SceneAddRender(const CRender &, const Entity &);
    void SceneAddTransform(const CTransform &, const Entity &);
    void SceneAddInput(const CInput &, const Entity &);

    void Update();
};

#endif // !SCENE_HPP
