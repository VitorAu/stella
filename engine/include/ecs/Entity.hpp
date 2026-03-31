#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstddef>
#include <string>

class EntityManager;

class Entity
{
    friend class EntityManager;

  private:
    const std::size_t m_id;
    const std::string m_tag;
    bool m_isActive = true;

    Entity(const std::size_t, const std::string &);

  public:
    ~Entity();

    const std::size_t Id() const;
    const std::string &Tag() const;
    bool IsActive();
    
    void Deactivate();
};

#endif // !ENTITY_HPP
