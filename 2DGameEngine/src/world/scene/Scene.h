#pragma once

#include "world/entity/Entity.h"


namespace Engine {

    class ENGINE_API Scene
    {

    public:

        Scene() {};
        Scene(std::string name);
        ~Scene();

        inline std::string getName() { return m_name; }

        void addEntity(std::unique_ptr<Entity> entity);
        void removeEntity(int entityId);

        template<typename T>
        std::shared_ptr<T> getEntity(const int id) const
        {
            auto it = m_entities.find(id);
            if (it != m_entities.end())
            {
                return dynamic_cast<T>(it->second);
            }
            else
            {
                return nullptr;
            }
        }

    private:

        std::string m_name;
        std::unordered_map<int, std::shared_ptr<Entity>> m_entities;

    };

}

