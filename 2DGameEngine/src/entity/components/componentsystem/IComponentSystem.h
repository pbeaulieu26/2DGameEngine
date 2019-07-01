#pragma once

#include "entity/Entity.h"
#include "entity/components/BaseComponent.h"


namespace Engine {

    template<typename TComponent>
    class IComponentSystem
    {
    public:
        virtual void createComponent(int entityId) = 0;
        virtual void removeComponent(int entityId) = 0;
        virtual std::shared_ptr<TComponent> getComponent(int entityId) = 0;
        virtual void updateComponents() = 0;
    };

}