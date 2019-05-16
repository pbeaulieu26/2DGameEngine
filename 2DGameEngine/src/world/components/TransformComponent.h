#pragma once

#include "BaseComponent.h"


namespace Engine {

    class ENGINE_API TransformComponent : public BaseComponent
    {

    public:
        TransformComponent();
        ~TransformComponent();

        COMPONENT_INFO("TransformComponent")

    };

}

