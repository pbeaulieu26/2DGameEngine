#pragma once

#include "ShaderProgram.h"
#include "rendering/textures/animations/AnimatedTextureData.h"

#include <glm/glm.hpp>


class Shader2D : public ShaderProgram
{
public:

    Shader2D();
    void loadTransformationMatrix(glm::mat4& matrix);
    void loadProjectionMatrix(glm::mat4& matrix);
    void loadViewMatrix(glm::mat4& matrix);
    void loadSubTextureParams(const AnimatedTextureData& animatedTextureData);

private:
    
    GLint m_locationTransformationMatrix;
    GLint m_locationProjectionMatrix;
    GLint m_locationViewMatrix;

    GLint m_locationSubTextureX;
    GLint m_locationSubTextureY;
    GLint m_locationSubTextureSize;

};
