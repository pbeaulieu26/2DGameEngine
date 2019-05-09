#pragma once

#include "RawModel.h"

#include <glad/glad.h>


class VertexObjectLoader
{
public:

    virtual ~VertexObjectLoader();
    RawModel loadToVAO(float * const positions, GLint size);

private:

    GLuint createVAO();
    void storeDataInAttributeList(GLuint attributeNumber, GLint attributeSize, float * const data, GLint size);
    void unbindVAO();

private:

    std::vector<GLuint> m_vaos;
    std::vector<GLuint> m_vbos;

};


