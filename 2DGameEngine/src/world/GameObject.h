#pragma once

#include "components/BaseComponent.h"


namespace Engine {

    typedef std::unordered_map<std::size_t, BaseComponent*> IdToComponentPtrMap;

    class ENGINE_API GameObject
    {

    public:

        GameObject();
        virtual ~GameObject();

        template<class T, typename ... TArgs>
        T* addComponent(TArgs&&... args)
        {
            T* component = new T(std::forward<TArgs>(args)...);
            auto res = m_componentMap.insert(MyMap::value_type(T::getStaticId(), component));

            ENGINE_CORE_ASSERT(res.second, "Component already exists");
            return component;
        };


        template<typename T>
        T* getComponent()
        {
            auto it = m_componentMap.find(T::getStaticType());
            if (it != m_componentMap.end())
            {
                return *it;
            }
            else
            {
                return nullptr;
            }
        }


        template<typename T>
        T* removeComponent()
        {
            auto it = m_componentMap.find(T::getStaticType());
            if (it != m_componentMap.end())
            {
                delete it->second;
                m_componentMap.erase(it);
            }
        }

    private:

        IdToComponentPtrMap m_componentMap;

    };

}

