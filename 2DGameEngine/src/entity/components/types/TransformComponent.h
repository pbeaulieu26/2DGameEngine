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
        inline double getScale() const { return m_scale; }

        inline void moveTo(const Vector2d<int> position) { m_position = position; }
        inline void moveToX(const int x) { m_position.x = x; }
        inline void moveToY(const int y) { m_position.y = y; } 

        inline void setRotation(const double rotation) { m_rotation = rotation; }
        inline void setScale(const double scale) { m_scale = scale; }

    private:

        Vector2d<int> m_position;
        double m_rotation;
        double m_scale;

    };

}

