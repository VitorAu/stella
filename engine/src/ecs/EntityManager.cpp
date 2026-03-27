#include "ecs/EntityManager.hpp"

EntityManager::EntityManager() = default;

EntityManager::~EntityManager() = default;

EntityPointer EntityManager::AddEntity(const std::string &tag)
{
    auto e = EntityPointer(new Entity(++m_entitiesTotal, tag));
    m_entitiesToAdd.push_back(e);

    return e;
}

const EntityVector &EntityManager::Entities()
{
    return m_entities;
}

const EntityVector &EntityManager::Entities(const std::string &tag)
{

    return m_entitiesMap[tag];
}

void EntityManager::Update()
{
    for (auto &e : m_entitiesToAdd)
    {
        if (e->IsActive() == true)
        {
            m_entities.push_back(e);
            m_entitiesMap[e->Tag()].push_back(e);
        }
    }

    Delete();
}

void EntityManager::Delete()
{
    auto inactive = [](const EntityPointer &e) { return !e->IsActive(); };

    m_entitiesToAdd.clear();
    std::erase_if(m_entities, inactive);
    for (auto &[tag, vec] : m_entitiesMap)
    {
        std::erase_if(vec, inactive);
    }
}
