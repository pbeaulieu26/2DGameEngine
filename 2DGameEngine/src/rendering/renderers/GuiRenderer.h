#pragma once

#include "rendering/shaders/GuiShader.h"
#include "rendering/models/loaders/VertexObjectLoader.h"
#include "rendering/entities/GuiEntity.h"


class GuiRenderer
{
public:

    explicit GuiRenderer(VertexObjectLoader& vertexObjectLoader);

    GuiRenderer(const GuiRenderer&) = delete;
    void operator=(const GuiRenderer&) = delete;

    void render(const std::vector<GuiEntity>& guis);

private:

    void initializeGlContext();

private:

    RawModel m_quad;
    GuiShader m_shader;

};
