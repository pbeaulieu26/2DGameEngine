#include "pch.h"
#include "InputManager.h"


namespace Engine {

    std::unique_ptr<InputManager> InputManager::s_Instance = nullptr;

    void InputManager::setInputManager(std::unique_ptr<InputManager> inputManager)
    { 
        s_Instance = std::move(inputManager);
    }

    bool InputManager::isKeyPressed(int keycode)
    { 
        ENGINE_CORE_ASSERT(s_Instance != nullptr, "InputManager implementation not set");
        return s_Instance->isKeyPressedImpl(keycode); 
    }

    bool InputManager::isMouseButtonPressed(int button) 
    { 
        ENGINE_CORE_ASSERT(s_Instance != nullptr, "InputManager implementation not set");
        return s_Instance->isMouseButtonPressedImpl(button);
    }

    std::pair<double, double> InputManager::getMousePosition() 
    { 
        ENGINE_CORE_ASSERT(s_Instance != nullptr, "InputManager implementation not set");
        return s_Instance->getMousePositionImpl();
    }

}