#include "pch.h"
#include "AnimatedTexturedModel.h"

bool AnimatedTexturedModel::operator==(const AnimatedTexturedModel &other) const
{
    return texturedModel == other.texturedModel;
}

std::size_t AnimatedTexturedModel::Hasher::operator()(const AnimatedTexturedModel& texturedModel) const
{
    TexturedModel::Hasher hasher;
    return hasher(texturedModel.texturedModel);
}