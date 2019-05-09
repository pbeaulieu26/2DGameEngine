#include "DisplayManager.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* DisplayManager::m_window = nullptr;
InputCallback* DisplayManager::m_inputCallback = nullptr;

int DisplayManager::createDisplay(int width, int height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, "GameEngine", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return MANAGER_ERROR;
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, DisplayManager::framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return MANAGER_ERROR;
    }

    return MANAGER_SUCCESS;
}

void DisplayManager::updateDisplay()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void DisplayManager::closeDisplay()
{
    glfwTerminate();
}

bool DisplayManager::isCloseRequested()
{
    return glfwWindowShouldClose(m_window);
}

void DisplayManager::processInput()
{
    if (m_inputCallback)
    {
        m_inputCallback(m_window);
    }
}

void DisplayManager::registerInputCallback(InputCallback* callback)
{
    m_inputCallback = callback;
}

void DisplayManager::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
