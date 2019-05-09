#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"

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

    TextureLoader textureLoader;
    textureLoader.loadTexture("res/green_texture.png");

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();
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