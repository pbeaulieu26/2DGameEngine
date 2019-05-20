#pragma once

#include "components/BaseComponent.h"


namespace Engine {

    typedef std::unordered_map<std::size_t, BaseComponent*> IdToComponentPtrMap;

    class ENGINE_API Entity
    {

    public:

        Entity() = delete;
        Entity(int id);
        virtual ~Entity();

        const int getId() const { return m_id; }

        template<class T, typename ... TArgs>
        T* createComponent(TArgs&&... args)
        {
            T* component = new T(std::forward<TArgs>(args)...);
            auto res = m_componentMap.insert(m_componentMap::value_type(T::getStaticId(), component));

            ENGINE_CORE_ASSERT(res.second, "Component already exists");
            return component;
        };


        template<typename T>
        T* getComponent()
        {
            auto it = m_componentMap.find(T::getStaticType());
            if (it != m_componentMap.end())
            {
                return it->second;
            }
            else
            {
                return nullptr;
            }
        }


        template<typename T>
        void removeComponent()
        {
            auto it = m_componentMap.find(T::getStaticType());
            if (it != m_componentMap.end())
            {
                delete it->second;
                m_componentMap.erase(it);
            }
        }

    private:

        int m_id;
        IdToComponentPtrMap m_componentMap;

    };

}

