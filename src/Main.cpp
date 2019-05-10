#include "pch.h"
#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/renderers/GuiRenderer.h"
#include "rendering/renderers/Renderer2D.h"
#include "rendering/entities/GuiEntity.h"
#include "rendering/entities/Entity.h"
#include "engine/Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void processInput(GLFWwindow* window);

int main()
{
    Engine::Log::Init();
    LOG_INFO("Logger initialized");

    int code = DisplayManager::createDisplay(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (code != MANAGER_SUCCESS)
    {
        return code;
    }

    DisplayManager::registerInputCallback(processInput);

    // Gui rendering initialization

    VertexObjectLoader vertexObjectLoader;
    GuiRenderer guiRenderer(vertexObjectLoader);

    TextureLoader textureLoader;
    GuiEntity gui(textureLoader.loadTexture("res/red_texture.png"), glm::vec2(-0.5, -0.5), glm::vec2(0.5, 0.5));
    std::vector<GuiEntity> guis{ gui };

    // Entity rendering initialization

    Renderer2D renderer2D;

    float positions[] = { -1, 1, -1, -1, 1, 1, 1, -1 };
    RawModel quad = vertexObjectLoader.loadToVAO(positions, 8);
    int texture = textureLoader.loadTexture("res/green_texture.png");

    TexturedModel texturedModel(quad, texture);
    Entity entity(texturedModel, glm::vec2(0.0, 0.0), 1.0, glm::vec2(0.5, 0.5));
    std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher> entities;
    entities[texturedModel] = std::vector<Entity>{ entity };

    // Game loop

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();

        guiRenderer.render(guis);
        renderer2D.render(entities);

        DisplayManager::updateDisplay();
    }

    DisplayManager::closeDisplay();

    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}