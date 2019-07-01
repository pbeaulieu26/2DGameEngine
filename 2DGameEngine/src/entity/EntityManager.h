#pragma once

#include "Entity.h"


namespace Engine {

    class ENGINE_API EntityManager
    {
    public:
        static EntityManager& getInstance()
        {
            return m_instance;
        }

        bool EntityIsAlive(EntityId entityId);

        EntityId createEntity();

        void removeEntity(EntityId entityId);

    private:
        EntityManager();

        static EntityManager m_instance;

        std::set<EntityId> m_freeIdsSet;
        std::set<EntityId> m_entitySet;
    };

}
