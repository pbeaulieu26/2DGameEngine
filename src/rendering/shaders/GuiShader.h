#pragma once

#include "ShaderProgram.h"

#include <glm/glm.hpp>


class GuiShader : public ShaderProgram
{
public:

    GuiShader();
    void loadTransformation(const glm::mat4& matrix);

private:
    
    GLint m_locationTransformationMatrix;

};
