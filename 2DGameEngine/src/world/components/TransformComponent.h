#pragma once

#include "BaseComponent.h"
#include "utils/Vector2d.h"


namespace Engine {

    class ENGINE_API TransformComponent : public BaseComponent
    {

    public:

        TransformComponent();
        TransformComponent(int xPos, int yPos, double rotation);
        TransformComponent(const Vector2d<int> position, double rotation);
        ~TransformComponent();

        inline Vector2d<int> getPosition() const { return m_position; }
        inline double getRotation() const { return m_rotation; }

        inline void moveTo(const Vector2d<int> position) { m_position = position; }
        inline void moveToX(const int x) { m_position.x = x; }
        inline void moveToY(const int y) { m_position.y = y; } 

        inline void setRotation(double rotation) { m_rotation = rotation; }

        COMPONENT_INFO("TransformComponent")

    private:

        Vector2d<int> m_position;
        double m_rotation;

    };

}

