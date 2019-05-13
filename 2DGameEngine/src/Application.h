#pragma once

#include "events/Event.h"
#include "events/EventDispatcher.h"


struct GLFWwindow;

namespace Engine {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    class ENGINE_API Application
    {

    public:
        Application();
        virtual ~Application();

        void run();

    protected:

        virtual void pollInputs(GLFWwindow* window);
        
        virtual void onMouseButtonPressedEvent(std::unique_ptr<Event> event);
        virtual void onMouseButtonReleasedEvent(std::unique_ptr<Event> event);
        virtual void onMouseMovedEvent(std::unique_ptr<Event> event);

        virtual void onKeyPressedEvent(std::unique_ptr<Event> event);
        virtual void onKeyReleasedEvent(std::unique_ptr<Event> event);

        virtual void onWindowCloseEvent(std::unique_ptr<Event> event);

    private:

        void onEvent(std::unique_ptr<Event> event);

        bool m_isRunning;
        std::unique_ptr<EventDispatcher> m_eventDispatcher;
        std::vector<std::unique_ptr<Event>> m_events;

    };

    Application* CreateApplication();
}

