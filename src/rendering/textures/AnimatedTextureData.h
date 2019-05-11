#pragma once


struct AnimatedTextureData
{
public:

    AnimatedTextureData() = default;

    void nextSubTexture();

    int subTextureX;
    int subTextureY;
    int subTextureSize;
    int subTextureCount;

};

