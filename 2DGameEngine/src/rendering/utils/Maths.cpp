#include "pch.h"
#include "Maths.h"

#include <glm/gtc/matrix_transform.hpp>


glm::mat4 Maths::createTransformationMatrix(const glm::vec2& translation, float rotation, const glm::vec2& scale)
{
    glm::mat4 matrix(1.0);

    matrix = glm::rotate(matrix, rotation, glm::vec3(0, 0, 1));
    matrix = glm::translate(matrix, glm::vec3(translation.x, translation.y, 0));
    matrix = glm::scale(matrix, glm::vec3(scale.x, scale.y, 1));

    return matrix;
}

glm::mat4 Maths::createTransformationMatrix(const glm::vec2& translation, const glm::vec2& scale)
{
    glm::mat4 matrix(1.0);

    matrix = glm::translate(matrix, glm::vec3(translation.x, translation.y, 0));
    matrix = glm::scale(matrix, glm::vec3(scale.x, scale.y, 1));

    return matrix;
}

glm::mat4 Maths::createViewMatrix(const glm::vec2& translation, float rotation)
{
    glm::mat4 matrix(1.0);

    matrix = glm::rotate(matrix, rotation, glm::vec3(0, 0, 1));
    matrix = glm::translate(matrix, glm::vec3(-translation.x, -translation.y, 0));

    return matrix;
}