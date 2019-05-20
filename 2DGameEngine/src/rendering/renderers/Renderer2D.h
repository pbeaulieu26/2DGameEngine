#pragma once

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/loaders/VertexObjectLoader.h"
#include "rendering/entities/Camera.h"
#include "rendering/entities/RenderEntity.h"
#include "rendering/entities/AnimatedEntity.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/display/DisplayManager.h"

namespace Engine {

    class ENGINE_API Renderer2D
    {
    public:

        Renderer2D();

        void render(const std::unordered_map<TexturedModel, std::vector<RenderEntity>, TexturedModel::Hasher>& entities, const Camera& camera);
        void render(const std::unordered_map<TexturedModel, std::vector<AnimatedEntity>, TexturedModel::Hasher>& entities, const Camera& camera);

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

}