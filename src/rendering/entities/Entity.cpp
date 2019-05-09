#include "pch.h"
#include "Entity.h"

Entity::Entity(const TexturedModel& texturedModel, const glm::vec2& position, const glm::vec2& rotation, const glm::vec2& scale)
    : texturedModel(texturedModel)
    , position(position)
    , rotation(rotation)
    , scale(scale)
{
}
