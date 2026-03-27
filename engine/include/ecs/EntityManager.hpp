#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <memory>
#include <unordered_map>
#include <vector>

#include "Entity.hpp"

using EntityPointer = std::shared_ptr<Entity>;
using EntityVector = std::vector<EntityPointer>;
using EntityMap = std::unordered_map<std::string, EntityVector>;

class Scene;

class EntityManager
{
  private:
    friend class Scene;

  private:
    EntityVector m_entities;
    EntityVector m_entitiesToAdd;
    EntityMap m_entitiesMap;

    int m_entitiesTotal = 0;

    EntityPointer AddEntity(const std::string &);

    const EntityVector &Entities();
    const EntityVector &Entities(const std::string &);

    void Update();
    void Delete();

  public:
    EntityManager();
    ~EntityManager();
};

#endif // !ENTITYMANAGER_HPP
