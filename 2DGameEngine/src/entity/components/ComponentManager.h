#pragma once

#include "entity/Entity.h"
#include "entity/components/types/BaseComponent.h"


namespace Engine {

    class ComponentManager
    {

    public:

        static ComponentManager& getInstance() 
        {
            return m_instance;
        };

        template<typename T>
        ComponentId createComponent(EntityId entityId)
        {
            /*auto it = m_freeIdsSet.begin();
            const int currentId = *it;
            m_entitySet.insert(currentId);
            m_freeIdsSet.erase(it);
            if (m_freeIdsSet.empty())
            {
                m_freeIdsSet.insert(currentId + 1);
            }*/

            // Create the component for entity entityId
            //  set the id

            // return currentId;

            return ComponentId();
        }

        template<typename T>
        void removeComponent(EntityId entityId)
        {
        }

    private:

        static ComponentManager m_instance;

        //std::set<EntityId> m_freeIdsSet;
    };

}