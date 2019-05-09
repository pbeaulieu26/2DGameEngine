#pragma once

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/entities/Entity.h"
#include "rendering/models/TexturedModel.h"


class Renderer2D
{
public:

    Renderer2D();

    void render(const std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher>& entities);

private:

    void initializeGlContext();
    void prepareTexturedModel(const TexturedModel& texturedModel);
    void unbindTexturedModel();

private:

    RawModel m_quad;
    Shader2D m_shader;

};

