#include "pch.h"
#include "DisplayManager.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

#include <GLFW/glfw3.h>


GLFWwindow* DisplayManager::m_window = nullptr;
std::vector<std::function<void(GLFWwindow*)>> DisplayManager::m_inputCallbacks;
std::vector<std::function<void(const WindowSize&)>> DisplayManager::m_resizeCallbacks;

int DisplayManager::createDisplay(int width, int height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    m_window = glfwCreateWindow(width, height, "GameEngine", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return MANAGER_ERROR;
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, DisplayManager::framebufferSizeCallback);

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
    m_inputCallbacks.clear();
    m_resizeCallbacks.clear();
    glfwTerminate();
}

bool DisplayManager::isCloseRequested()
{
    return glfwWindowShouldClose(m_window);
}

void DisplayManager::processInput()
{
    for (auto callback : m_inputCallbacks)
    {
        callback(m_window);
    }
}

void DisplayManager::registerInputCallback(std::function<void(GLFWwindow*)> callback)
{
    m_inputCallbacks.push_back(callback);
}

void DisplayManager::registerResizeCallback(std::function<void(const WindowSize&)> callback)
{
    m_resizeCallbacks.push_back(callback);
}

void DisplayManager::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    for (auto callback : m_resizeCallbacks)
    {
        callback(WindowSize{ width, height });
    }
    
    glViewport(0, 0, width, height);
}

WindowSize DisplayManager::getWindowSize()
{
    WindowSize windowSize;
    glfwGetWindowSize(m_window, &windowSize.width, &windowSize.height);
    return windowSize;
}
