#pragma once

#include "Entity.h"


namespace Engine {

    class EntityManager
    {

    public:

        template<class T, typename ... TArgs>
        static std::unique_ptr<T> addEntity(TArgs&&... args)
        {
            T* entity = new T(std::forward<TArgs>(args)...);
            return std::make_unique<T>(entity);
        };

    private:

        static int m_idCounter;

    };

}

