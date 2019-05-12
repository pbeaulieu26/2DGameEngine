#include "pch.h"
#include "Application.h"
#include "events/EventDispatcher.h"
#include "events/Event.h"
#include "events/MouseEvent.h"
#include "events/KeyboardEvent.h"
#include "events/WindowEvent.h"


namespace Engine {

    Application::Application()
        : m_eventDispatcher(std::make_unique<EventDispatcher>())
    {
        m_eventDispatcher->registerCallback(EventType::MouseMoved, std::bind(&Application::onMouseMovedEvent, this, std::placeholders::_1));
        m_eventDispatcher->registerCallback(EventType::MouseButtonPressed, std::bind(&Application::onMouseButtonPressedEvent, this, std::placeholders::_1));
        m_eventDispatcher->registerCallback(EventType::MouseButtonReleased, std::bind(&Application::onMouseButtonReleasedEvent, this, std::placeholders::_1));
        m_eventDispatcher->registerCallback(EventType::KeyPressed, std::bind(&Application::onKeyPressedEvent, this, std::placeholders::_1));
        m_eventDispatcher->registerCallback(EventType::KeyReleased, std::bind(&Application::onKeyReleasedEvent, this, std::placeholders::_1));
        m_eventDispatcher->registerCallback(EventType::WindowClose, std::bind(&Application::onWindowCloseEvent, this, std::placeholders::_1));
    }


    Application::~Application()
    {
    }


    void Application::run() 
    {
        while (true)
        {
            // handle events

            // update game

            // update window
        }
    }


    void Application::onEvent(const Event& event)
    {
        // dispatch events based on type
        m_eventDispatcher->dispatchEvent(event);
    }


    void Application::onMouseButtonPressedEvent(const Event& event)
    {
        const MouseButtonPressedEvent* mouseMovedEvent = dynamic_cast<const MouseButtonPressedEvent*>(&event);
        LOG_CORE_WARN("Unhandled : ", event.toString());
    }


    void Application::onMouseButtonReleasedEvent(const Event& event)
    {
        const MouseButtonReleasedEvent* mouseMovedEvent = dynamic_cast<const MouseButtonReleasedEvent*>(&event);
        LOG_CORE_WARN("Unhandled : ", event.toString());
    }


    void Application::onMouseMovedEvent(const Event& event)
    {
        const MouseMovedEvent* mouseMovedEvent = dynamic_cast<const MouseMovedEvent*>(&event);
        LOG_CORE_WARN("Unhandled : ", event.toString());
    }


    void Application::onKeyPressedEvent(const Event& event)
    {
        const KeyPressedEvent* mouseMovedEvent = dynamic_cast<const KeyPressedEvent*>(&event);
        LOG_CORE_WARN("Unhandled : ", event.toString());
    }


    void Application::onKeyReleasedEvent(const Event& event)
    {
        const KeyReleasedEvent* mouseMovedEvent = dynamic_cast<const KeyReleasedEvent*>(&event);
        LOG_CORE_WARN("Unhandled : ", event.toString());
    }


    void Application::onWindowCloseEvent(const Event& event)
    {
        const WindowCloseEvent* mouseMovedEvent = dynamic_cast<const WindowCloseEvent*>(&event);
        LOG_CORE_WARN("Unhandled : ", event.toString());
    }

}
