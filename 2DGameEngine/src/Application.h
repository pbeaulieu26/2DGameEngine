#pragma once

#include "events/Event.h"
#include "events/EventDispatcher.h"


namespace Engine {

    class ENGINE_API Application
    {

    public:
        Application();
        virtual ~Application();

        void run();

        void onEvent(const Event& event);

    protected:
        virtual void onMouseButtonPressedEvent(const Event& event);
        virtual void onMouseButtonReleasedEvent(const Event& event);
        virtual void onMouseMovedEvent(const Event& event);

        virtual void onKeyPressedEvent(const Event& event);
        virtual void onKeyReleasedEvent(const Event& event);

        virtual void onWindowCloseEvent(const Event& event);

    private:
        bool m_isRunning;
        std::unique_ptr<EventDispatcher> m_eventDispatcher;

    };

    Application* CreateApplication();
}

