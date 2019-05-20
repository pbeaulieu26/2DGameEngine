#pragma once

#include "rendering/models/TexturedModel.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

struct ENGINE_API RenderEntity
{
public:

    RenderEntity() = default;

    TexturedModel texturedModel;
    glm::vec2 position;
    float rotation;
    glm::vec2 scale;

};
