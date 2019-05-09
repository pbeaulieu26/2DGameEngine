#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>

struct GuiEntity
{
public:

    GuiEntity() = default;
    GuiEntity(GLuint texture, const glm::vec2& position, const glm::vec2& scale);

    GLuint texture;
    glm::vec2 position;
    glm::vec2 scale;

};
