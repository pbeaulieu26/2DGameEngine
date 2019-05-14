#include "pch.h"
#include "GLFWInputManager.h"
#include <GLFW/glfw3.h>


namespace Engine {

    GLFWInputManager::GLFWInputManager(GLFWwindow* window)
        : m_window(window)
    {

    }


    GLFWInputManager::~GLFWInputManager()
    {

    }

    bool GLFWInputManager::isKeyPressedImpl(int keycode)
    {
        int state = glfwGetKey(m_window, keycode);
        return state == GLFW_PRESS;
    }


    bool GLFWInputManager::isMouseButtonPressedImpl(int button)
    {
        int state = glfwGetMouseButton(m_window, button);
        return state == GLFW_PRESS;
    }


    std::pair<double, double> GLFWInputManager::getMousePositionImpl()
    {
        double xpos, ypos;
        glfwGetCursorPos(m_window, &xpos, &ypos);
        return std::pair<double, double>(xpos, ypos);
    }

}