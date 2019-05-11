#pragma once

#include <glad/glad.h>

struct ENGINE_API RawModel
{
public:

    RawModel() = default;

    GLuint vaoId;
    int vertexCount;

};


