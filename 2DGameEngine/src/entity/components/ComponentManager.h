#pragma once
#include "BaseComponent.h"
#include "entity/Entity.h"


namespace Engine {

    class ComponentManager
    {

    public:

        static ComponentManager& getInstance();

    private:

        static ComponentManager m_instance;
    };

}