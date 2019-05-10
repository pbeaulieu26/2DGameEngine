#include "pch.h"
#include "Shader2D.h"


namespace
{
    const char * vertexShaderFile = "src/rendering/shaders/vertexShader.txt";
    const char * fragmentShaderFile = "src/rendering/shaders/fragmentShader.txt";
    const std::vector<const GLchar *> attributes{ "position", "textureCoords" };
}

Shader2D::Shader2D()
    : ShaderProgram(vertexShaderFile, fragmentShaderFile, attributes)
{
    m_locationTransformationMatrix = getUniformLocation("transformationMatrix");
    m_locationProjectionMatrix = getUniformLocation("projectionMatrix");
    m_locationViewMatrix = getUniformLocation("viewMatrix");
}

void Shader2D::loadTransformationMatrix(glm::mat4& matrix)
{
    loadMatrix(m_locationTransformationMatrix, matrix);
}

void Shader2D::loadProjectionMatrix(glm::mat4& matrix)
{
    loadMatrix(m_locationProjectionMatrix, matrix);
}

void Shader2D::loadViewMatrix(glm::mat4& matrix)
{
    loadMatrix(m_locationViewMatrix, matrix);
}
