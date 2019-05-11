#pragma once

#include <glm/glm.hpp>


class ENGINE_API Camera
{
public:

    Camera() = default;

    glm::vec2 position;
    float rotation;

};

