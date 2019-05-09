#pragma once

#include "RawModel.h"
#include <glad/glad.h>


struct TexturedModel
{
public:

    struct Hasher
    {
        std::size_t operator()(const TexturedModel& texturedModel) const;
    };

    TexturedModel() = default;
    TexturedModel(const RawModel& rawModel, const GLuint& texture);

    bool operator==(const TexturedModel &other) const;

    RawModel rawModel;
    GLuint texture;

};
