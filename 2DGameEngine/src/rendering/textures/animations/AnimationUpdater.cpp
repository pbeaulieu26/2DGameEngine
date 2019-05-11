#include "pch.h"
#include "AnimationUpdater.h"


void AnimationUpdater::bindAnimatedTextureData(AnimatedTextureData& animatedTextureData)
{
    m_animationUpdateFunctions.push_back(std::bind(&AnimatedTextureData::nextSubTexture, &animatedTextureData));
}

void AnimationUpdater::update()
{
    for (const std::function<void()>& updateAnimation : m_animationUpdateFunctions)
    {
        updateAnimation();
    }
}

void AnimationUpdater::unbindAll()
{
    m_animationUpdateFunctions.clear();
}