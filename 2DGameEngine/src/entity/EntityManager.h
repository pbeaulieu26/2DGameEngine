#pragma once

#include "Entity.h"


namespace Engine {

    class EntityManager
    {

    public:

        static EntityManager& getInstance()
        {
            return m_instance;
        }

        EntityId createEntity();
        void removeEntity(EntityId entityId);

    private:

        static EntityManager m_instance;
    };

}
