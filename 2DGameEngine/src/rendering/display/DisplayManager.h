#pragma once

#include "events/EventDispatcher.h"
#include "WindowSize.h"


struct GLFWwindow;
struct GLFWvidmode;

namespace Engine {

    enum ENGINE_API ErrorCode
    {
        MANAGER_SUCCESS = 0,
        MANAGER_ERROR = 1
    };

    class ENGINE_API DisplayManager
    {
    public:

        DisplayManager() = delete;

        static int createDisplay(int width, int height);
        static void updateDisplay();
        static void closeDisplay();
        static bool isCloseRequested();
        
        static GLFWwindow* getWindow();
        
        static WindowSize getWindowSize();

    private:

        // glfw callbacks
        static void resizeEventCallback(GLFWwindow* window, int width, int height);
        static void keyEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouseCursorEventCallback(GLFWwindow* window, double xpos, double ypos);
        static void mouseButtonEventCallback(GLFWwindow* window, int button, int action, int mods);
        static void mouseScrollEventCallback(GLFWwindow* window, double xpos, double ypos);
        static void windowCloseEventCallback(GLFWwindow* window);
        static void windowFocusEventCallback(GLFWwindow* window, int focused);

    private:

        static GLFWwindow* m_window;
        static EventDispatcher& m_eventDispatcher;
    };

}
