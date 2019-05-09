#pragma once

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/entities/GuiEntity.h"

class GuiRenderer
{
public:

    explicit GuiRenderer(VertexObjectLoader& vertexObjectLoader);

    void render(const std::vector<GuiEntity>& guis);

private:

    void initializeGlContext();

private:

    RawModel m_quad;
    Shader2D m_shader;

};
