#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

struct GLFWwindow;

typedef void InputCallback(GLFWwindow*);

enum ErrorCode
{
    MANAGER_SUCCESS = 0,
    MANAGER_ERROR = 1
};

class DisplayManager
{
public:

    static int createDisplay(int width, int height);
    static void updateDisplay();
    static void closeDisplay();
    static bool isCloseRequested();
    static void processInput();
    static void registerInputCallback(InputCallback* callback);

private:

    DisplayManager();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:

    static GLFWwindow* m_window;
    static InputCallback* m_inputCallback;
};

#endif // !DISPLAY_MANAGER_H
