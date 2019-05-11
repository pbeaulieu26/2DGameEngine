#pragma once

#include "AnimatedTextureData.h"

#include <functional>


class ENGINE_API AnimationUpdater
{
public:

    void bindAnimatedTextureData(AnimatedTextureData& animatedTextureData);
    void update();
    void unbindAll();

private:

    std::vector<std::function<void()>> m_animationUpdateFunctions;

};

