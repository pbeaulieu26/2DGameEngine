#include "VertexObjectLoader.h"
#include "RawModel.h"
#include "rendering/stb/stb_image.h"


VertexObjectLoader::~VertexObjectLoader()
{
    for (GLuint vao : m_vaos)
    {
        glDeleteVertexArrays(1, &vao);
    }
    for (GLuint vbo : m_vbos)
    {
        glDeleteBuffers(1, &vbo);
    }
}

RawModel VertexObjectLoader::loadToVAO(float * const positions, GLint size)
{
    GLuint vaoID = createVAO();
    storeDataInAttributeList(0, 2, positions, size);
    unbindVAO();
    return RawModel(vaoID, size / 2);
}

GLuint VertexObjectLoader::createVAO()
{
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    m_vaos.push_back(vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}

void VertexObjectLoader::storeDataInAttributeList(GLuint attributeNumber, GLint attributeSize, float * const data, GLint size)
{
    GLuint vboID;
    glGenBuffers(1, &vboID);
    m_vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data) * size, data, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, attributeSize, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexObjectLoader::unbindVAO()
{
    glBindVertexArray(0);
}