#pragma once

#include "events/Event.h"


struct GLFWwindow;
struct GLFWvidmode;

namespace Engine {

    enum ENGINE_API ErrorCode
    {
        MANAGER_SUCCESS = 0,
        MANAGER_ERROR = 1
    };

    struct ENGINE_API WindowSize
    {
        int width;
        int height;
    };

    class ENGINE_API DisplayManager
    {
    public:

        DisplayManager() = delete;

        static int createDisplay(int width, int height);
        static void updateDisplay();
        static void closeDisplay();
        static bool isCloseRequested();

        static void registerResizeCallback(std::function<void(const WindowSize&)> callback);
        static void registerEventCallback(EventFn callback);
        
        static GLFWwindow* getWindow();
        
        static WindowSize getWindowSize();

    private:

        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

        // glfw callbacks
        static void keyEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouseCursorEventCallback(GLFWwindow* window, double xpos, double ypos);
        static void mouseButtonEventCallback(GLFWwindow* window, int button, int action, int mods);
        static void mouseScrollEventCallback(GLFWwindow* window, double xpos, double ypos);
        static void windowCloseEventCallback(GLFWwindow* window);
        static void windowFocusEventCallback(GLFWwindow* window, int focused);

    private:

        static GLFWwindow* m_window;
        static std::vector<std::function<void(GLFWwindow*)>> m_inputCallbacks;
        static std::vector < std::function<void(const WindowSize&)>> m_resizeCallbacks;
        static EventFn m_appEventCallback;
    };

}
