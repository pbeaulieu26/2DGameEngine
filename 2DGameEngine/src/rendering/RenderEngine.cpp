#include "pch.h"
#include "RenderEngine.h"
#include "rendering/models/loaders/ObjFileLoader.h"
#include "rendering/models/TexturedModel.h"

namespace Engine
{

    TexturedModel RenderEngine::createTexturedModel(const std::string& modelFile, const std::string& textureFile)
    {
        RawModel rawModel = m_vertexObjectLoader.loadToVAO(ObjFileLoader::loadOBJ(modelFile));
        return TexturedModel{ rawModel, m_textureLoader.loadTexture(textureFile.c_str()) };
    }

    void RenderEngine::registerEntity(const Entity& entity)
    {
        auto iter = m_entities.find(entity.texturedModel);
        if (iter == m_entities.end())
        {
            m_entities[entity.texturedModel] = std::vector<Entity>{ entity };
        }
        else
        {
            iter->second.push_back(entity);
        }
    }

    void RenderEngine::registerAnimatedEntity(const AnimatedEntity& animatedEntity, bool animate)
    {
        const TexturedModel& texturedModel = animatedEntity.animatedTexturedModel.texturedModel;
        auto iter = m_animatedEntities.find(texturedModel);
        if (iter == m_animatedEntities.end())
        {
            m_animatedEntities[texturedModel] = std::vector<AnimatedEntity>{ animatedEntity };
        }
        else
        {
            iter->second.push_back(animatedEntity);
        }

        if (animate)
        {
            m_animationUpdater.bindAnimatedTextureData(m_animatedEntities[texturedModel].back().animatedTexturedModel.animatedTextureData);
        }
    }

    void RenderEngine::renderEntities(const Camera& camera, bool animateEntities)
    {
        if (animateEntities)
        {
            m_animationUpdater.update();
        }
        
        m_renderer2D.render(m_entities, camera);
        m_renderer2D.render(m_animatedEntities, camera);
    }

}