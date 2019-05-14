#pragma once

#include "Core.h"


namespace Engine {

    class ENGINE_API InputManager
    {

    public:
        static void setInputManager(std::unique_ptr<InputManager> inputManager);

        static bool isKeyPressed(int keycode);

        static bool isMouseButtonPressed(int button);
        static std::pair<double, double> getMousePosition();

    protected:
        virtual bool isKeyPressedImpl(int keycode) = 0;

        virtual bool isMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<double, double> getMousePositionImpl() = 0;

    private:
        static std::unique_ptr<InputManager> s_Instance;

    };

    

}