#include "pch.h"
#include "TexturedModel.h"


bool TexturedModel::operator==(const TexturedModel &other) const
{
    return (texture == other.texture) && (rawModel.vaoId == other.rawModel.vaoId);
}

std::size_t TexturedModel::Hasher::operator()(const TexturedModel& texturedModel) const
{
    return (std::hash<int>()(texturedModel.texture) ^ (std::hash<int>()(texturedModel.rawModel.vaoId) << 1));
}