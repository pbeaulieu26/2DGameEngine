#pragma once

#include "pch.h"


namespace Engine {

    enum class ENGINE_API EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };


#define EVENT_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
                         virtual EventType getEventType() const override { return getStaticType(); }\
                         virtual const char* getName() const override { return #type; }


    class ENGINE_API Event
    {

    public:
        Event() {};
        virtual ~Event() {};

        virtual EventType getEventType() const = 0;

        virtual const char* getName() const = 0;

        virtual std::string toString() const { return getName(); }

    };

    typedef std::function<void(std::unique_ptr<Event> e)> EventFn;

}