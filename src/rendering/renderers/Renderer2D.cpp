#include "pch.h"
#include "Renderer2D.h"
#include "rendering/utils/Maths.h"

#include <glad/glad.h>

Renderer2D::Renderer2D()
    : m_projectionMatrix(1)
{
    initializeGlContext();
    WindowSize windowSize = DisplayManager::getWindowSize();
    createProjectionMatrix(windowSize);
    DisplayManager::registerResizeCallback(std::bind(&Renderer2D::createProjectionMatrix, this, std::placeholders::_1));
}

void Renderer2D::initializeGlContext()
{
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);
    glClearColor(0, 0, 0, 0);
}

void Renderer2D::render(const std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher>& entities)
{
    m_shader.start();

    m_shader.loadProjection(m_projectionMatrix);
    
    for (auto iter : entities)
    {
        const TexturedModel& texturedModel = iter.first;
        const std::vector<Entity>& batch = iter.second;
        prepareTexturedModel(texturedModel);

        for (const Entity& entity : batch)
        {
            glm::mat4 matrix = Maths::createTransformationMatrix(entity.position, entity.rotation, entity.scale);
            m_shader.loadTransformation(matrix);
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