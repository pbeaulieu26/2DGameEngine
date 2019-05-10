#include "pch.h"
#include "Entity.h"

Entity::Entity(const TexturedModel& texturedModel, const glm::vec2& position, float rotation, const glm::vec2& scale)
    : texturedModel(texturedModel)
    , position(position)
    , rotation(rotation)
    , scale(scale)
{
}
