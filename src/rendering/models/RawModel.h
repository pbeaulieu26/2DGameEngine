#pragma once

#include <glad/glad.h>

struct RawModel
{
public:

    RawModel() = default;
    RawModel(GLuint vaoId, int vertexCount);

    GLuint vaoId;
    int vertexCount;

};


