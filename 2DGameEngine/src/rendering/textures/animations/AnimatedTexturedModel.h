#pragma once

#include "AnimatedTextureData.h"
#include "rendering/models/TexturedModel.h"


struct AnimatedTexturedModel
{
public:

    struct Hasher
    {
        std::size_t operator()(const AnimatedTexturedModel& texturedModel) const;
    };

    AnimatedTexturedModel() = default;

    bool operator==(const AnimatedTexturedModel &other) const;

    TexturedModel texturedModel;
    AnimatedTextureData animatedTextureData;

};