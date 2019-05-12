#pragma once


namespace Engine {

    class Event; // Forward declaration

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
        virtual ~WindowCloseEvent() {}

        EVENT_TYPE(WindowClose)

    };

}