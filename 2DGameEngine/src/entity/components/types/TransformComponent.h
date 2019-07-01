#pragma once

#include "DataComponent.h"
#include "utils/Vector2d.h"


namespace Engine {

    class ENGINE_API TransformComponent : public DataComponent
    {

    public:

        void initialize() override;

        inline Vector2d<int> getPosition() const { return m_position; }
        inline double getRotation() const { return m_rotation; }
        inline double getScale() const { return m_scale; }

        inline void setPosition(const Vector2d<int> position) { m_position = position; }
        inline void setPositionX(const int x) { m_position.x = x; }
        inline void setPositionY(const int y) { m_position.y = y; } 

        inline void setRotation(const double rotation) { m_rotation = rotation; }
        inline void setScale(const double scale) { m_scale = scale; }

    private:

        Vector2d<int> m_position;
        double m_rotation;
        double m_scale;

    };

}

