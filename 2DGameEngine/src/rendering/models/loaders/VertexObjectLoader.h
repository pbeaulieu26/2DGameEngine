#pragma once

#include "rendering/models/RawModel.h"
#include "rendering/models/ModelData.h"

#include <glad/glad.h>


class ENGINE_API VertexObjectLoader
{
public:

    VertexObjectLoader() = default;
    virtual ~VertexObjectLoader();

    VertexObjectLoader(const VertexObjectLoader&) = delete;
    void operator=(const VertexObjectLoader&) = delete;

    RawModel loadToVAO(float* const positions, GLint size);
    RawModel loadToVAO(const ModelData& modelData);

private:

    GLuint createVAO();
    void storeDataInAttributeList(GLuint attributeNumber, GLint attributeSize, const float* data, GLint size);
    void bindIndicesBuffer(const int* indices, GLint size);
    void unbindVAO();

private:

    std::vector<GLuint> m_vaos;
    std::vector<GLuint> m_vbos;

};


