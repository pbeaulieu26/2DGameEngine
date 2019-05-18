#pragma once

#include "Entity.h"


namespace Engine {

    class EntityManager
    {

    public:

        EntityManager();
        ~EntityManager();

        template<class T, typename ... TArgs>
        T* addEntity(TArgs&&... args)
        {
            T* entity = new T(std::forward<TArgs>(args)...);
            auto res = m_entities.insert(m_entities::value_type(m_idCounter++, std::make_unique<T>(entity)));

            ENGINE_CORE_ASSERT(res.second, "Entity already exists at id: ", m_idCounter);
            return entity;
        };


        template<typename T>
        T* getEntity(const int id) const
        {
            auto it = m_entities.find(id);
            if (it != m_entities.end())
            {
                return dynamic_cast<T*>(it->second.get());
            }
            else
            {
                return nullptr;
            }
        }


        void deleteEntity(const int id);

    private:

        int m_idCounter;
        std::unordered_map<int, std::unique_ptr<Entity>> m_entities;

    };

}

