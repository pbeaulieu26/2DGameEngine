#pragma once


namespace Engine {

    class Event; // Forward declaration

    class ENGINE_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
        virtual ~WindowCloseEvent() {}

        EVENT_TYPE(WindowClose)

    };

    class ENGINE_API WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent() {}
        virtual ~WindowFocusEvent() {}

        EVENT_TYPE(WindowFocus)

    };

    class ENGINE_API WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent() {}
        virtual ~WindowLostFocusEvent() {}

        EVENT_TYPE(WindowLostFocus)

    };

}