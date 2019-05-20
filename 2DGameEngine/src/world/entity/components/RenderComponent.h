#pragma once

#include "BaseComponent.h"


namespace Engine {

    class ENGINE_API RenderComponent : public BaseComponent
    {

    public:
        RenderComponent();
        ~RenderComponent();

        COMPONENT_INFO("RenderComponent")

    };

}

