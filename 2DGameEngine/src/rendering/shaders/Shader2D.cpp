#include "pch.h"
#include "Shader2D.h"


namespace
{
    const char * vertexShaderFile = "res/shaders/vertexShader.txt";
    const char * fragmentShaderFile = "res/shaders/fragmentShader.txt";
    const std::vector<const GLchar *> attributes{ "position", "textureCoords" };
}

Shader2D::Shader2D()
    : ShaderProgram(vertexShaderFile, fragmentShaderFile, attributes)
{
    m_locationTransformationMatrix = getUniformLocation("transformationMatrix");
    m_locationProjectionMatrix = getUniformLocation("projectionMatrix");
    m_locationViewMatrix = getUniformLocation("viewMatrix");

    m_locationSubTextureX = getUniformLocation("subTextureX");
    m_locationSubTextureY = getUniformLocation("subTextureY");
    m_locationSubTextureSize = getUniformLocation("subTextureSize");
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

void Shader2D::loadSubTextureParams(const AnimatedTextureData& animatedTextureData)
{
    loadFloat(m_locationSubTextureX, animatedTextureData.subTextureX);
    loadFloat(m_locationSubTextureY, animatedTextureData.subTextureY);
    loadFloat(m_locationSubTextureSize, animatedTextureData.subTextureSize);
}
