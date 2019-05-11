#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>

struct ENGINE_API GuiEntity
{
public:

    GuiEntity() = default;

    GLuint texture;
    glm::vec2 position;
    glm::vec2 scale;

};
