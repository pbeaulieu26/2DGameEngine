#include "pch.h"
#include "GuiShader.h"


namespace
{
    const char * vertexShaderFile = "res/shaders/guiVertexShader.txt";
    const char * fragmentShaderFile = "res/shaders/guiFragmentShader.txt";
    const std::vector<const GLchar *> attributes{ "position" };
}

GuiShader::GuiShader()
    : ShaderProgram(vertexShaderFile, fragmentShaderFile, attributes)
{
    m_locationTransformationMatrix = getUniformLocation("transformationMatrix");
}

void GuiShader::loadTransformationMatrix(const glm::mat4& matrix)
{
    loadMatrix(m_locationTransformationMatrix, matrix);
}
