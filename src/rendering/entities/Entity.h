#pragma once

#include "rendering/models/TexturedModel.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

struct Entity
{
public:

    Entity() = default;
    Entity(const TexturedModel& texturedModel, const glm::vec2& position, const glm::vec2& rotation, const glm::vec2& scale);

    TexturedModel texturedModel;
    glm::vec2 position;
    glm::vec2 rotation;
    glm::vec2 scale;

};
