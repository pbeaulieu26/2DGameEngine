#pragma once

#include "AnimatedTextureData.h"
#include "rendering/models/TexturedModel.h"


struct ENGINE_API AnimatedTexturedModel
{
public:

    struct ENGINE_API Hasher
    {
        std::size_t operator()(const AnimatedTexturedModel& texturedModel) const;
    };

    AnimatedTexturedModel() = default;

    bool operator==(const AnimatedTexturedModel &other) const;

    TexturedModel texturedModel;
    AnimatedTextureData animatedTextureData;

};