#pragma once
#include "types/BaseComponent.h"
#include "entity/Entity.h"


namespace Engine {

    class ComponentManager
    {

    public:

        static ComponentManager& getInstance() 
        {
            return m_instance;
        };

    private:

        static ComponentManager m_instance;
    };

}