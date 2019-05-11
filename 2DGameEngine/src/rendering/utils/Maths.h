#pragma once

#include <glm/glm.hpp>


class ENGINE_API Maths
{
public:

    Maths() = delete;

    static glm::mat4 createTransformationMatrix(const glm::vec2& translation, float rotation, const glm::vec2& scale);
    static glm::mat4 createTransformationMatrix(const glm::vec2& translation, const glm::vec2& scale);
    static glm::mat4 createViewMatrix(const glm::vec2& translation, float rotation);

};

