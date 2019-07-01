#include "pch.h"
#include "TransformComponent.h"


namespace Engine {

    void TransformComponent::initialize()
    {
        m_position = Vector2d<int>(0, 0);
        m_rotation = 0;
        m_scale = 1;
    }

}
