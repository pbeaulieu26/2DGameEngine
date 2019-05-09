#pragma once

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/entities/Entity.h"


class Renderer2D
{
public:

    explicit Renderer2D(VertexObjectLoader& vertexObjectLoader);

    void render(const std::vector<Entity>& entities);

private:

    void initializeGlContext();

private:

    RawModel m_quad;
    Shader2D m_shader;

};

