#pragma once

#include "BaseComponent.h"


namespace Engine {

    class ENGINE_API DataComponent : public BaseComponent
    {
        virtual void initialize() = 0;
    };

}
