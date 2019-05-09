#include "pch.h"
#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/renderers/GuiRenderer.h"
#include "rendering/entities/GuiEntity.h"
#include "engine/Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void processInput(GLFWwindow *window);

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

    TextureLoader textureLoader;
    GuiEntity gui1(textureLoader.loadTexture("res/green_texture.png"), glm::vec2(0.0, 0.0), glm::vec2(0.5, 0.5));
    GuiEntity gui2(textureLoader.loadTexture("res/red_texture.png"), glm::vec2(-1.0, -1.0), glm::vec2(0.5, 0.5));
    std::vector<GuiEntity> guis{ gui1, gui2 };

    VertexObjectLoader vertexObjectLoader;
    GuiRenderer renderer(vertexObjectLoader);

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();

        renderer.render(guis);

        DisplayManager::updateDisplay();
    }

    DisplayManager::closeDisplay();

    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}