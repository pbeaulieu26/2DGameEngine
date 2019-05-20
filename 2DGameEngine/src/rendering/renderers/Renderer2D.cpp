#include "pch.h"
#include "Renderer2D.h"
#include "rendering/utils/Maths.h"

#include <glad/glad.h>

namespace Engine {

    Renderer2D::Renderer2D()
        : m_projectionMatrix(1.0)
    {
        initializeGlContext();
        WindowSize windowSize = DisplayManager::getWindowSize();
        createProjectionMatrix(windowSize);
    }

    void Renderer2D::initializeGlContext()
    {
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_DEPTH_TEST);
        glActiveTexture(GL_TEXTURE0);
    }

    void Renderer2D::render(const std::unordered_map<TexturedModel, std::vector<RenderEntity>, TexturedModel::Hasher>& entities, const Camera& camera)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        m_shader.start();

        // No animation, select subtexture which equals the texture
        m_shader.loadSubTextureParams(AnimatedTextureData{ 0, 0, 1, 1 });

        glm::mat4 viewMatrix = Maths::createViewMatrix(camera.position, camera.rotation);
        m_shader.loadProjectionMatrix(m_projectionMatrix);
        m_shader.loadViewMatrix(viewMatrix);

        for (auto iter : entities)
        {
            const TexturedModel& texturedModel = iter.first;
            const std::vector<RenderEntity>& batch = iter.second;
            prepareTexturedModel(texturedModel);

            for (const RenderEntity& entity : batch)
            {
                glm::mat4 transformationMatrix = Maths::createTransformationMatrix(entity.position, entity.rotation, entity.scale);
                m_shader.loadTransformationMatrix(transformationMatrix);
               glDrawElements(GL_TRIANGLES, entity.texturedModel.rawModel.vertexCount, GL_UNSIGNED_INT, 0);
            }

            unbindTexturedModel();
        }

        m_shader.stop();
    }

    void Renderer2D::render(const std::unordered_map<TexturedModel, std::vector<AnimatedEntity>, TexturedModel::Hasher>& entities, const Camera& camera)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        m_shader.start();

        glm::mat4 viewMatrix = Maths::createViewMatrix(camera.position, camera.rotation);
        m_shader.loadProjectionMatrix(m_projectionMatrix);
        m_shader.loadViewMatrix(viewMatrix);

        for (auto iter : entities)
        {
            const TexturedModel& texturedModel = iter.first;
            const std::vector<AnimatedEntity>& batch = iter.second;
            prepareTexturedModel(texturedModel);
        
            for (const AnimatedEntity& animatedEntity : batch)
            {
                m_shader.loadSubTextureParams(animatedEntity.animatedTexturedModel.animatedTextureData);
                glm::mat4 transformationMatrix = Maths::createTransformationMatrix(animatedEntity.position, animatedEntity.rotation, animatedEntity.scale);
                m_shader.loadTransformationMatrix(transformationMatrix);
                glDrawElements(GL_TRIANGLES, texturedModel.rawModel.vertexCount, GL_UNSIGNED_INT, 0);
            }

            unbindTexturedModel();
        }
  
        m_shader.stop();
    }

    void Renderer2D::prepareTexturedModel(const TexturedModel& texturedModel)
    {
        glBindVertexArray(texturedModel.rawModel.vaoId);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glBindTexture(GL_TEXTURE_2D, texturedModel.texture);
    }

    void Renderer2D::unbindTexturedModel()
    {
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    void Renderer2D::createProjectionMatrix(const WindowSize& windowSize)
    {
        float aspectRatio = float(windowSize.width) / float(windowSize.height);
        m_projectionMatrix[1][1] = aspectRatio;
    }

}