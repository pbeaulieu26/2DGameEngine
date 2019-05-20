#include "pch.h"

#include "Application.h"
#include "events/EventDispatcher.h"
#include "input/GLFWInputManager.h"

#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/textures/animations/AnimationUpdater.h"
#include "rendering/textures/animations/AnimatedTexturedModel.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/models/loaders/VertexObjectLoader.h"
#include "rendering/renderers/GuiRenderer.h"
#include "rendering/renderers/Renderer2D.h"
#include "rendering/entities/GuiEntity.h"
#include "rendering/entities/Entity.h"
#include "rendering/entities/Camera.h"
#include "rendering/models/ModelData.h"
#include "rendering/models/loaders/ObjFileLoader.h"
#include "rendering/RenderEngine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chrono>
#include <thread>


namespace Engine {

    Application::Application()
        : m_eventDispatcher(EventDispatcher::getInstance())
    {
        Log::Init();
        LOG_CORE_INFO("Logger initialized");

        m_eventDispatcher.registerCallback<MouseScrolledEvent>(std::bind(&Application::onMouseMovedEvent, this, std::placeholders::_1));
        m_eventDispatcher.registerCallback<MouseButtonPressedEvent>(std::bind(&Application::onMouseButtonPressedEvent, this, std::placeholders::_1));
        m_eventDispatcher.registerCallback<MouseButtonReleasedEvent>(std::bind(&Application::onMouseButtonReleasedEvent, this, std::placeholders::_1));
        m_eventDispatcher.registerCallback<KeyPressedEvent>(std::bind(&Application::onKeyPressedEvent, this, std::placeholders::_1));
        m_eventDispatcher.registerCallback<KeyReleasedEvent>(std::bind(&Application::onKeyReleasedEvent, this, std::placeholders::_1));
        m_eventDispatcher.registerCallback<WindowCloseEvent>(std::bind(&Application::onWindowCloseEvent, this, std::placeholders::_1));

        int code = DisplayManager::createDisplay(SCREEN_WIDTH, SCREEN_HEIGHT);
        if (code != MANAGER_SUCCESS)
        {
            LOG_CORE_ERROR("Could not create display");
            std::cin.get();
            exit(code);
        }

        InputManager::setInputManager(std::make_unique<GLFWInputManager>(DisplayManager::getWindow()));
    }


    Application::~Application()
    {
    }


    void Application::run()
    {
        Camera camera{ glm::vec2(0.4, 0.0), 0.0f };

        RenderEngine renderEngine;

        TexturedModel textureModel = renderEngine.createTexturedModel("res/hex.obj", "res/forest_texture.png");
        AnimatedEntity entity1{ AnimatedTexturedModel{textureModel, 0, 0, 4, 16}, glm::vec2(0.0, 0.0), 0.0, glm::vec2(0.2, 0.2) };
        AnimatedEntity entity2{ AnimatedTexturedModel{textureModel, 0, 0, 4, 16}, glm::vec2(0.35, 0.0), 0.0, glm::vec2(0.2, 0.2) };

        renderEngine.registerAnimatedEntity(entity1);
        renderEngine.registerAnimatedEntity(entity2);

        int counter = 0;

        m_isRunning = true;

        while (m_isRunning)
        {
            // handle events
            m_eventDispatcher.dispatchEvents();

            // update window
            bool updateAnimation = !(bool) (++counter %= 6);
            renderEngine.renderEntities(camera, updateAnimation);

            DisplayManager::updateDisplay();

            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }

        DisplayManager::closeDisplay();
    }

    void Application::close()
    {
        m_isRunning = false;
    }


    void Application::onMouseButtonPressedEvent(const MouseButtonPressedEvent& event)
    {
        LOG_CORE_WARN("Unhandled : {0}", event.toString());
    }


    void Application::onMouseButtonReleasedEvent(const MouseButtonReleasedEvent& event)
    {
        LOG_CORE_WARN("Unhandled : {0}", event.toString());
    }


    void Application::onMouseMovedEvent(const MouseScrolledEvent& event)
    {
        LOG_CORE_WARN("Unhandled : {0}", event.toString());
    }


    void Application::onKeyPressedEvent(const KeyPressedEvent& event)
    {
        LOG_CORE_WARN("Unhandled : {0}", event.toString());
    }


    void Application::onKeyReleasedEvent(const KeyReleasedEvent& event)
    {
        LOG_CORE_WARN("Unhandled : {0}", event.toString());
    }


    void Application::onWindowCloseEvent(const WindowCloseEvent& event)
    {
        m_isRunning = false;
    }

}
