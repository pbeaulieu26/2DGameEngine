#include "pch.h"
#include "EntityManager.h"


namespace Engine {

    EntityManager EntityManager::m_instance;

    EntityManager::EntityManager()
    {
        m_freeIdsSet.insert(0);
    }

    bool EntityManager::EntityIsAlive(EntityId entityId)
    {
        return m_entitySet.count(entityId) != 0;
    }

    EntityId EntityManager::createEntity()
    {
        auto it = m_freeIdsSet.begin();
        const int currentId = *it;
        m_entitySet.insert(currentId);
        m_freeIdsSet.erase(it);
        if (m_freeIdsSet.empty())
        {
            m_freeIdsSet.insert(currentId + 1);
        }
        return currentId;
    }

    void EntityManager::removeEntity(EntityId entityId)
    {
        m_entitySet.erase(entityId);
        m_freeIdsSet.insert(entityId);
    }

}