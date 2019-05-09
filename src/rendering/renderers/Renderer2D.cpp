#include "pch.h"
#include "Renderer2D.h"
#include "rendering/utils/Maths.h"

#include <glad/glad.h>


Renderer2D::Renderer2D(VertexObjectLoader& vertexObjectLoader)
{
    float positions[] = { -1, 1, -1, -1, 1, 1, 1, -1 };
    m_quad = vertexObjectLoader.loadToVAO(positions, 8);
    initializeGlContext();
}

void Renderer2D::initializeGlContext()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);
    glClearColor(0, 0, 0, 0);
}

void Renderer2D::render(const std::vector<Entity>& entities)
{
    m_shader.start();
    glBindVertexArray(m_quad.vaoId);
    glEnableVertexAttribArray(0);

    for (const Entity& entity : entities)
    {
        glBindTexture(GL_TEXTURE_2D, entity.texturedModel.texture);
        glm::mat4 matrix = Maths::createTransformationMatrix(entity.position, entity.scale);
        m_shader.loadTransformation(matrix);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, m_quad.vertexCount);
    }

    glBindVertexArray(0);
    m_shader.stop();
}