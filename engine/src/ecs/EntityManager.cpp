#include "ecs/EntityManager.hpp"

EntityManager::EntityManager() = default;

EntityManager::~EntityManager() = default;

EntityPointer EntityManager::CreateEntity(const std::string &entityTag)
{
    EntityPointer e(new Entity(m_entitiesTotal++, entityTag));
    m_entitiesToAdd.push_back(e);

    return e;
}

const EntityVector &EntityManager::Entities()
{
    return m_entitiesVec;
}

const EntityVector &EntityManager::Entities(const std::string &entityTag)
{
    return m_entitiesMap[entityTag];
}

void EntityManager::Update()
{
    for (auto &e : m_entitiesToAdd)
    {
        if (e->IsActive() == true)
        {
            m_entitiesVec.push_back(e);
            m_entitiesMap[e->Tag()].push_back(e);
        }
    }

    Delete();
}

void EntityManager::Delete()
{
    auto inactive = [](const EntityPointer &e) { return !e->IsActive(); };

    m_entitiesToAdd.clear();
    std::erase_if(m_entitiesVec, inactive);
    for (auto &[tag, vec] : m_entitiesMap)
    {
        std::erase_if(vec, inactive);
    }
}
