#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include "ecs/Entity.hpp"

#include <memory>
#include <unordered_map>
#include <vector>

class Scene;

using EntityPointer = std::shared_ptr<Entity>;
using EntityVector = std::vector<EntityPointer>;
using EntityMap = std::unordered_map<std::string, EntityVector>;

class EntityManager
{
    friend class Scene;

  private:
    EntityVector m_entitiesToAdd;
    EntityVector m_entitiesVec;
    EntityMap m_entitiesMap;
    std::size_t m_entitiesTotal = 0;

    EntityPointer CreateEntity(const std::string &);
    const EntityVector &Entities();
    const EntityVector &Entities(const std::string &);

    void Update();
    void Delete();

  public:
    EntityManager();
    ~EntityManager();
};

#endif // !ENTITYMANAGER_HPP
