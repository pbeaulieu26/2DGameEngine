#pragma once

#include "AnimatedTextureData.h"
#include "rendering/models/TexturedModel.h"


struct ENGINE_API AnimatedTexturedModel
{
public:

    AnimatedTexturedModel() = default;

    TexturedModel texturedModel;
    AnimatedTextureData animatedTextureData;

};