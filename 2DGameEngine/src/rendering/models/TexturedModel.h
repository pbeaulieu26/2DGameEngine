#pragma once

#include "RawModel.h"
#include "rendering/textures/animations/AnimatedTextureData.h"

#include <glad/glad.h>


struct ENGINE_API TexturedModel
{
public:

    struct ENGINE_API Hasher
    {
        std::size_t operator()(const TexturedModel& texturedModel) const;
    };

    TexturedModel() = default;

    bool operator==(const TexturedModel &other) const;

    RawModel rawModel;
    GLuint texture;

};
