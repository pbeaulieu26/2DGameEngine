#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>


struct Texture
{
public:

    Texture() = default;
    Texture(GLuint id, glm::vec2 position, glm::vec2 scale);

    GLuint id;
    glm::vec2 position;
    glm::vec2 scale;

};
