#ifndef SHADER_2D_H
#define SHADER_2D_H

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

#endif // !SHADER_2D_H