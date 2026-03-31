#include "ecs/Entity.hpp"

Entity::Entity(const std::size_t id, const std::string &tag) : m_id(id), m_tag(tag)
{
}

Entity::~Entity() = default;

const std::size_t Entity::Id() const
{
    return m_id;
}

const std::string &Entity::Tag() const
{
    return m_tag;
}

bool Entity::IsActive()
{
    return m_isActive;
}

void Entity::Destroy()
{
    m_isActive = false;
}
