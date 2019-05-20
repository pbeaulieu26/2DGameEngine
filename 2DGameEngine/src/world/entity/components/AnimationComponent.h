#pragma once

#include "BaseComponent.h"


namespace Engine {

    class ENGINE_API AnimationComponent : public BaseComponent
    {

    public:
        AnimationComponent();
        ~AnimationComponent();

        COMPONENT_INFO("AnimationComponent")

    };

}

