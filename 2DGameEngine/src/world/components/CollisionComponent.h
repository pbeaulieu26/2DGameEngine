#pragma once

#include "BaseComponent.h"


namespace Engine {

    class ENGINE_API CollisionComponent : public BaseComponent
    {

    public:
        CollisionComponent();
        ~CollisionComponent();

        COMPONENT_INFO("CollisionComponent")

    };

}

