#pragma once

#include "rendering/models/loaders/VertexObjectLoader.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/entities/AnimatedEntity.h"
#include "rendering/entities/Entity.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/renderers/Renderer2D.h"
#include "rendering/entities/Camera.h"
#include "rendering/textures/animations/AnimationUpdater.h"

namespace Engine
{

    class ENGINE_API RenderEngine
    {
    public:

        RenderEngine() = default;

        RenderEngine(const RenderEngine&) = delete;
        void operator=(const RenderEngine&) = delete;

        TexturedModel createTexturedModel(const std::string& modelFile, const std::string& textureFile);

        void registerEntity(const Entity& entity);
        void registerAnimatedEntity(const AnimatedEntity& animatedEntity, bool animate = true);
        void renderEntities(const Camera& camera, bool animateEntities);

    private:

        AnimationUpdater m_animationUpdater;
        Renderer2D m_renderer2D;
        TextureLoader m_textureLoader;
        VertexObjectLoader m_vertexObjectLoader;

        std::unordered_map<TexturedModel, std::vector<AnimatedEntity>, TexturedModel::Hasher> m_animatedEntities;
        std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher> m_entities;
    };

}