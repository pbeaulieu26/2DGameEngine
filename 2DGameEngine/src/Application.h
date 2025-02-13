#pragma once

#include "events/MouseEvent.h"
#include "events/KeyboardEvent.h"
#include "events/WindowEvent.h"
#include "events/ApplicationEvent.h"


class EventDispatcher;
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

        void close();

    protected:

        virtual void onMouseButtonPressedEvent(const MouseButtonPressedEvent& event);
        virtual void onMouseButtonReleasedEvent(const MouseButtonReleasedEvent& event);
        virtual void onMouseMovedEvent(const MouseScrolledEvent& event);

        virtual void onKeyPressedEvent(const KeyPressedEvent& event);
        virtual void onKeyReleasedEvent(const KeyReleasedEvent& event);

        virtual void onWindowCloseEvent(const WindowCloseEvent& event);

        virtual void onAppUpdateEvent(const AppUpdateEvent& event);

    private:

        void onApplicationMouseButtonPressedEvent(const MouseButtonPressedEvent& event);
        void onApplicationMouseButtonReleasedEvent(const MouseButtonReleasedEvent& event);
        void onApplicationMouseMovedEvent(const MouseScrolledEvent& event);

        void onApplicationKeyPressedEvent(const KeyPressedEvent& event);
        void onApplicationKeyReleasedEvent(const KeyReleasedEvent& event);

        void onApplicationWindowCloseEvent(const WindowCloseEvent& event);

        void onApplicationAppUpdateEvent(const AppUpdateEvent& event);


        bool m_isRunning;
        EventDispatcher& m_eventDispatcher;

    };

    Application* CreateApplication();
}

