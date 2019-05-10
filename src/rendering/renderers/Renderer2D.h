#pragma once

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/entities/Entity.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/display/DisplayManager.h"


class Renderer2D
{
public:

    Renderer2D();

    void render(const std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher>& entities);

    Renderer2D(const Renderer2D&) = delete;
    void operator=(const Renderer2D&) = delete;

private:

    void initializeGlContext();
    void prepareTexturedModel(const TexturedModel& texturedModel);
    void unbindTexturedModel();
    void createProjectionMatrix(const WindowSize& windowSize);

private:

    RawModel m_quad;
    Shader2D m_shader;

    glm::mat4 m_projectionMatrix;

};

