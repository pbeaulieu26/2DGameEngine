#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/textures/Texture.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/renderers/Renderer2D.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void processInput(GLFWwindow *window);

int main()
{
    int code = DisplayManager::createDisplay(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (code != MANAGER_SUCCESS)
    {
        return code;
    }

    DisplayManager::registerInputCallback(processInput);

    Texture texture;
    TextureLoader textureLoader;
    texture.id = textureLoader.loadTexture("res/green_texture.png");
    texture.position = glm::vec2(0.0, 0.0);
    texture.scale = glm::vec2(1.0, 1.0);
    std::vector<Texture> textures{ texture };

    VertexObjectLoader vertexObjectLoader;
    Renderer2D renderer(vertexObjectLoader);

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();

        renderer.render(textures);

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