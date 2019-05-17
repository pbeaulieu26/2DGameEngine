#include "pch.h"
#include "TransformComponent.h"


namespace Engine {

    TransformComponent::TransformComponent()
        : m_position()
    {
    }

    TransformComponent::TransformComponent(int xPos, int yPos, double rotation)
        : m_position(xPos, yPos), m_rotation(rotation)
    {
    }

    TransformComponent::TransformComponent(const Vector2d<int> position, double rotation)
        : m_position(position), m_rotation(rotation)
    {
    }


    TransformComponent::~TransformComponent()
    {
    }

}
