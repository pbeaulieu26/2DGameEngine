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

}