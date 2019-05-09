#pragma once

#include <glm/glm.hpp>


class Maths
{
public:

    Maths() = delete;

    static glm::mat4 createTransformationMatrix(const glm::vec2& translation, const glm::vec2& scale);

};

