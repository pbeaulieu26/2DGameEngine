#include "pch.h"
#include "GuiEntity.h"

GuiEntity::GuiEntity(GLuint texture, const glm::vec2& position, const glm::vec2& scale)
    : texture(texture)
    , position(position)
    , scale(scale)
{
}
