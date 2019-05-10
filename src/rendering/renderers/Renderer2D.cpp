#include "pch.h"
#include "Renderer2D.h"
#include "rendering/utils/Maths.h"

#include <glad/glad.h>


Renderer2D::Renderer2D()
{
    initializeGlContext();
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
    
    for (auto iter : entities)
    {
        const TexturedModel& texturedModel = iter.first;
        const std::vector<Entity>& batch = iter.second;
        prepareTexturedModel(texturedModel);

        for (const Entity& entity : batch)
        {
            glm::mat4 matrix = Maths::createTransformationMatrix(entity.position, entity.rotation, entity.scale);
            m_shader.loadTransformation(matrix);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, texturedModel.rawModel.vertexCount);
        }

        unbindTexturedModel();
    }

    m_shader.stop();
}

void Renderer2D::prepareTexturedModel(const TexturedModel& texturedModel)
{
    glBindVertexArray(texturedModel.rawModel.vaoId);
    glEnableVertexAttribArray(0);
    //glEnableVertexAttribArray(1);
    glBindTexture(GL_TEXTURE_2D, texturedModel.texture);
}

void Renderer2D::unbindTexturedModel()
{
    glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}