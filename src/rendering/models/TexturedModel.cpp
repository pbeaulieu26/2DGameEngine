#include "pch.h"
#include "TexturedModel.h"

TexturedModel::TexturedModel(const RawModel& rawModel, const GLuint& texture)
    : rawModel(rawModel)
    , texture(texture)
{
}