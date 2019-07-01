#pragma once

#include "BaseComponent.h"


namespace Engine {

    class ENGINE_API BehaviorComponent : public BaseComponent
    {
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
    };

}

