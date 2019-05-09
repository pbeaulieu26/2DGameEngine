#pragma once

#include "ShaderProgram.h"

#include <glm/glm.hpp>


class Shader2D : public ShaderProgram
{
public:

    Shader2D();
    void loadTransformation(glm::mat4& matrix);

private:
    
    GLint m_locationTransformationMatrix;

};
