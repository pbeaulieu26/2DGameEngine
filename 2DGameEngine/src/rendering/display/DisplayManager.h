#pragma once

#include <functional>

struct GLFWwindow;
struct GLFWvidmode;

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
    static void processInput();
    static void registerInputCallback(std::function<void(GLFWwindow*)> callback);
    static void registerResizeCallback(std::function<void(const WindowSize&)> callback);
    static WindowSize getWindowSize();

private:

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

private:

    static GLFWwindow* m_window;
    static std::vector<std::function<void(GLFWwindow*)>> m_inputCallbacks;
    static std::vector < std::function<void(const WindowSize&)>> m_resizeCallbacks;
};

