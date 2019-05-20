#include "pch.h"
#include "Entity.h"


namespace Engine {

    Entity::Entity()
    {
        static int m_idCounter = 0;

        m_id = m_idCounter++;
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
