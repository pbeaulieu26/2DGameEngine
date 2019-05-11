#include "pch.h"
#include "AnimatedTextureData.h"

void AnimatedTextureData::nextSubTexture()
{
    if (++subTextureX == subTextureSize)
    {
        ++subTextureY;
        subTextureX = 0;
        subTextureY %= subTextureSize;
    }

    if (subTextureX + subTextureY * subTextureSize == subTextureCount)
    {
        subTextureX = 0;
        subTextureY = 0;
    }
}
