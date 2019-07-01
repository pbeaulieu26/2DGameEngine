#pragma once

#include "entity/Entity.h"


namespace Engine {

    template<typename TComponent>
    class BaseComponentSystem
    {
    public:
        virtual void updateComponents() = 0;

        void createComponent(EntityId entityId) override
        {
            m_componentMap[entityId] = std::make_shared<TComponent>();
        }

        void removeComponent(EntityId entityId) override
        {
            m_componentMap.erase(entityId);
        }

        std::shared_ptr<TComponent> getComponent(EntityId entityId) override
        {
            auto it = m_componentMap.find(entityId);
            return it != m_componentMap.end() ? (*it).second : nullptr;
        }

    private:
        std::map<int, std::shared_ptr<TComponent>> m_componentMap;

    };

}
