#pragma once

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/entities/Camera.h"
#include "rendering/entities/Entity.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/display/DisplayManager.h"
#include "rendering/textures/animations/AnimatedTexturedModel.h"


class ENGINE_API Renderer2D
{
public:

    Renderer2D();

    void render(const std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher>& entities, const Camera& camera);
    void render(const std::unordered_map<AnimatedTexturedModel, std::vector<Entity>, AnimatedTexturedModel::Hasher>& entities, const Camera& camera);

    Renderer2D(const Renderer2D&) = delete;
    void operator=(const Renderer2D&) = delete;

private:

    void initializeGlContext();
    void processEntities(const std::vector<Entity>& entities);
    void prepareTexturedModel(const TexturedModel& texturedModel);
    void unbindTexturedModel();
    void createProjectionMatrix(const WindowSize& windowSize);

private:

    RawModel m_quad;
    Shader2D m_shader;

    glm::mat4 m_projectionMatrix;

};

