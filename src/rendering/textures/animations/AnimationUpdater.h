#pragma once

#include "AnimatedTextureData.h"

#include <functional>


class AnimationUpdater
{
public:

    void bindAnimatedTextureData(AnimatedTextureData& animatedTextureData);
    void update();
    void unbindAll();

private:

    std::vector<std::function<void()>> m_animationUpdateFunctions;

};

