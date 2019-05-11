#pragma once

#include "RawModel.h"
#include "rendering/textures/AnimatedTextureData.h"

#include <glad/glad.h>


struct TexturedModel
{
public:

    struct Hasher
    {
        std::size_t operator()(const TexturedModel& texturedModel) const;
    };

    TexturedModel() = default;

    bool operator==(const TexturedModel &other) const;

    RawModel rawModel;
    GLuint texture;

    AnimatedTextureData animatedTextureData;

};
