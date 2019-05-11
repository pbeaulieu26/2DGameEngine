#pragma once

#include "ShaderProgram.h"

#include <glm/glm.hpp>


class ENGINE_API GuiShader : public ShaderProgram
{
public:

    GuiShader();
    void loadTransformationMatrix(const glm::mat4& matrix);

private:
    
    GLint m_locationTransformationMatrix;

};
