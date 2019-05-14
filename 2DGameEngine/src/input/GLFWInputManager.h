#pragma once

#include "InputManager.h"


struct GLFWwindow;

namespace Engine {

    class GLFWInputManager : public InputManager
    {

    public:
        GLFWInputManager(GLFWwindow* window);
        ~GLFWInputManager();

        virtual bool isKeyPressedImpl(int keycode) override;

        virtual bool isMouseButtonPressedImpl(int button) override;
        virtual std::pair<double, double> getMousePositionImpl() override;

    private:
        GLFWwindow* m_window;
    };

}

