#include "pch.h"
#include "EntityManager.h"


namespace Engine {

    EntityManager::EntityManager()
    {
    }


    EntityManager::~EntityManager()
    {
        for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
        {
            it->second.reset();
        }

        m_entities.clear();
    }


    void EntityManager::deleteEntity(const int id)
    {
        auto it = m_entities.find(id);
        if (it != m_entities.end())
        {
            it->second.reset();
            m_entities.erase(it);
        }
    }

}