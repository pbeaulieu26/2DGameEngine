#pragma once

#include "RawModel.h"
#include "VerticesData.h"

#include <glad/glad.h>


class ENGINE_API VertexObjectLoader
{
public:

    VertexObjectLoader() = default;
    virtual ~VertexObjectLoader();

    VertexObjectLoader(const VertexObjectLoader&) = delete;
    void operator=(const VertexObjectLoader&) = delete;

    RawModel loadToVAO(float* const positions, GLint size);
    RawModel loadToVAO(const VerticesData& verticesData);

private:

    GLuint createVAO();
    void storeDataInAttributeList(GLuint attributeNumber, GLint attributeSize, float* const data, GLint size);
    void bindIndicesBuffer(int* indices, GLint size);
    void unbindVAO();

private:

    std::vector<GLuint> m_vaos;
    std::vector<GLuint> m_vbos;

};


