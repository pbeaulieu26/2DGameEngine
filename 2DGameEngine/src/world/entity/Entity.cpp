#include "pch.h"
#include "Entity.h"


namespace Engine {

    Entity::Entity(int id)
        : m_id(id)
    {
    }


    Entity::~Entity()
    {
        for (auto it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
        {
            delete it->second;
        }

        m_componentMap.clear();
    }

}
