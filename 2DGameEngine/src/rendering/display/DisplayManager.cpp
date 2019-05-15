#include "pch.h"
#include "DisplayManager.h"
#include "events/KeyboardEvent.h"
#include "events/MouseEvent.h"
#include "events/WindowEvent.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>
#include <GLFW/glfw3.h>


namespace Engine {

    GLFWwindow* DisplayManager::m_window = nullptr;
    EventDispatcher& DisplayManager::m_eventDispatcher = EventDispatcher::getInstance();

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

        glfwSetFramebufferSizeCallback(m_window, resizeEventCallback);
        glfwSetKeyCallback(m_window, keyEventCallback);
        glfwSetCursorPosCallback(m_window, mouseCursorEventCallback);
        glfwSetMouseButtonCallback(m_window, mouseButtonEventCallback);
        glfwSetScrollCallback(m_window, mouseScrollEventCallback);
        glfwSetWindowCloseCallback(m_window, windowCloseEventCallback);
        glfwSetWindowFocusCallback(m_window, windowFocusEventCallback);

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

    GLFWwindow * DisplayManager::getWindow()
    {
        return m_window;
    }

    void DisplayManager::resizeEventCallback(GLFWwindow* window, int width, int height)
    {
        m_eventDispatcher.queueEvent(WindowResizeEvent(WindowSize{width, height}));

        glViewport(0, 0, width, height);
    }

    void DisplayManager::keyEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            m_eventDispatcher.queueEvent(KeyPressedEvent(key));
        }
        else if (action == GLFW_RELEASE)
        {
            m_eventDispatcher.queueEvent(KeyReleasedEvent(key));
        }
    }

    void DisplayManager::mouseCursorEventCallback(GLFWwindow* window, double xpos, double ypos)
    {
        m_eventDispatcher.queueEvent(MouseMovedEvent(xpos, ypos));
    }

    void DisplayManager::mouseButtonEventCallback(GLFWwindow* window, int button, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            m_eventDispatcher.queueEvent(MouseButtonPressedEvent(button));
        }
        else if (action == GLFW_RELEASE)
        {
            m_eventDispatcher.queueEvent(MouseButtonReleasedEvent(button));
        }
    }

    void DisplayManager::mouseScrollEventCallback(GLFWwindow* window, double xoffset, double yoffset)
    {
        m_eventDispatcher.queueEvent(MouseScrolledEvent(xoffset, yoffset));
    }

    void DisplayManager::windowCloseEventCallback(GLFWwindow* window)
    {
        m_eventDispatcher.queueEvent(WindowCloseEvent());
    }

    void DisplayManager::windowFocusEventCallback(GLFWwindow* window, int focused)
    {
        if (focused)
        {
            m_eventDispatcher.queueEvent(WindowFocusEvent());
        }
        else
        {
            m_eventDispatcher.queueEvent(WindowLostFocusEvent());
        }
    }

    WindowSize DisplayManager::getWindowSize()
    {
        WindowSize windowSize;
        glfwGetWindowSize(m_window, &windowSize.width, &windowSize.height);
        return windowSize;
    }

}