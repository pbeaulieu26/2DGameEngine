#pragma once

#include "rendering/textures/animations/AnimatedTexturedModel.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

struct ENGINE_API AnimatedEntity
{
public:

    AnimatedEntity() = default;

    AnimatedTexturedModel animatedTexturedModel;
    glm::vec2 position;
    float rotation;
    glm::vec2 scale;

};
