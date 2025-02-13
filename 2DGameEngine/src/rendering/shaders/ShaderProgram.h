#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>


class ENGINE_API ShaderProgram
{
public:

    ShaderProgram(const char * vertexFile, const char * fragmentFile, const std::vector<const GLchar *>& attributes);
    virtual ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    void operator=(const ShaderProgram&) = delete;
    
    GLint getUniformLocation(const GLchar * uniformName);
    void start();
    void stop();

protected:

    void loadFloat(GLint m_location, GLfloat value);
    void loadInt(GLint location, GLint value);
    void loadMatrix(GLint m_location, const glm::mat4& matrix);

private:

    void initializeProgram(const std::vector<const GLchar *>& attributes);
    void bindAttribute(GLint attribute, const GLchar * variableName);
    GLuint loadShader(const char * file, GLenum type);
    void validateProgram();

private:

    GLuint m_programID;
    GLuint m_vertexShaderID;
    GLuint m_fragmentShaderID;

};
