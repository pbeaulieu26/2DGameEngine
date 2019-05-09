#pragma once

#include "RawModel.h"
#include <glad/glad.h>

struct TexturedModel
{
public:

    TexturedModel() = default;
    TexturedModel(const RawModel& rawModel, const GLuint& texture);

    RawModel rawModel;
    GLuint texture;

};
