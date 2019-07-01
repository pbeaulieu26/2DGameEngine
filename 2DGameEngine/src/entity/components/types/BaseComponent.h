#pragma once

#include "core/Core.h"


namespace Engine {

    typedef int ComponentId;

    class ENGINE_API BaseComponent
    {
    public:
        inline ComponentId getId() { return id; }

        inline void activate() { m_isActivated = true; };
        inline void deactivate() { m_isActivated = false; };

        inline bool isActivated() { return m_isActivated; }

        friend class ComponentManager;

    private:
        BaseComponent();

        ComponentId id;
        bool m_isActivated;

    };

}

