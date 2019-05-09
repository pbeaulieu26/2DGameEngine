#include "ShaderProgram.h"

#include <string>
#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

ShaderProgram::ShaderProgram(const char* vertexFile, const char * fragmentFile, const std::vector<const GLchar *>& attributes)
{
    m_vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
    m_fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
    initializeProgram(attributes);
}

ShaderProgram::~ShaderProgram()
{
    stop();
    glDetachShader(m_programID, m_vertexShaderID);
    glDetachShader(m_programID, m_fragmentShaderID);
    glDeleteShader(m_vertexShaderID);
    glDeleteShader(m_fragmentShaderID);
    glDeleteProgram(m_programID);
}

void ShaderProgram::initializeProgram(const std::vector<const GLchar *>& attributes)
{
    m_programID = glCreateProgram();
    glAttachShader(m_programID, m_vertexShaderID);
    glAttachShader(m_programID, m_fragmentShaderID);

    int attributeIndex = 0;
    for (const char * attribute : attributes)
    {
        bindAttribute(attributeIndex++, attribute);
    }

    glLinkProgram(m_programID);
    validateProgram();
}

GLint ShaderProgram::getUniformLocation(const GLchar * uniformName)
{
    return glGetUniformLocation(m_programID, uniformName);
}

void ShaderProgram::start()
{
    glUseProgram(m_programID);
}

void ShaderProgram::stop()
{
    glUseProgram(0);
}

void ShaderProgram::bindAttribute(GLint attribute, const GLchar * variableName)
{
    glBindAttribLocation(m_programID, attribute, variableName);
}

void ShaderProgram::loadFloat(GLint location, GLfloat value)
{
    glUniform1f(location, value);
}

void ShaderProgram::loadMatrix(GLint location, glm::mat4& matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    glm::value_ptr(matrix);
}

GLuint ShaderProgram::loadShader(const char * file, GLenum type)
{
    std::string line, fileString;
    std::ifstream myfile(file);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            fileString.append(line).append("\n");
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file " << file << std::endl;
    }

    const GLchar *shaderSource = fileString.c_str();

    GLuint shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &shaderSource, NULL);
    glCompileShader(shaderID);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "Shader compilation failed!" << std::endl << infoLog << std::endl;
    }

    return shaderID;
}

void ShaderProgram::validateProgram()
{
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(m_programID, GL_LINK_STATUS, &success);

    if (!success) 
    {
        glGetProgramInfoLog(m_programID, 512, NULL, infoLog);
        std::cout << "Shader linking failed" << std::endl << infoLog << std::endl;
    }
}