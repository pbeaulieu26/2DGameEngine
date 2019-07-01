#pragma once


namespace Engine {

    template<typename TComponent>
    class BaseComponentSystem
    {
    public:
        virtual void updateComponents() = 0;

        void createComponent(int entityId) override
        {
            m_componentMap[entityId] = std::make_shared<TComponent>();
        }

        void removeComponent(int entityId) override
        {
            m_componentMap.erase(entityId);
        }

        std::shared_ptr<TComponent> getComponent(int entityId) override
        {
            auto it = m_componentMap.find(entityId);
            return it != m_componentMap.end() ? (*it).second : nullptr;
        }

    private:
        std::map<int, std::shared_ptr<TComponent>> m_componentMap;

    };

}
