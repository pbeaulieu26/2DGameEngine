#include "GuiRenderer.h"
#include "rendering/utils/Maths.h"

#include <glad/glad.h>

GuiRenderer::GuiRenderer(VertexObjectLoader& vertexObjectLoader)
{
    float positions[] = { -1, 1, -1, -1, 1, 1, 1, -1 };
    m_quad = vertexObjectLoader.loadToVAO(positions, 8);
    initializeGlContext();
}

void GuiRenderer::initializeGlContext()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);
    glClearColor(0, 0, 0, 0);
}

void GuiRenderer::render(const std::vector<GuiEntity>& guis)
{
    m_shader.start();
    glBindVertexArray(m_quad.vaoId);
    glEnableVertexAttribArray(0);

    for (const GuiEntity& gui : guis)
    {
        glBindTexture(GL_TEXTURE_2D, gui.texture);
        glm::mat4 matrix = Maths::createTransformationMatrix(gui.position, gui.scale);
        m_shader.loadTransformation(matrix);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, m_quad.vertexCount);
    }

    glBindVertexArray(0);
    m_shader.stop();
}