#pragma once


struct ENGINE_API AnimatedTextureData
{
public:

    AnimatedTextureData() = default;

    void nextSubTexture();

    int subTextureX;
    int subTextureY;
    int subTextureSize;
    int subTextureCount;

};

