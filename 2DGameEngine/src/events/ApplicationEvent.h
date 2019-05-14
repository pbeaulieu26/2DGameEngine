#pragma once


namespace Engine {

    class Event; // Forward declaration

    class ENGINE_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}
        virtual ~AppTickEvent() {}

        EVENT_TYPE(AppTick)

    };


    class ENGINE_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}
        virtual ~AppUpdateEvent() {}

        EVENT_TYPE(AppUpdate)

    };


    class ENGINE_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}
        virtual ~AppRenderEvent() {}

        EVENT_TYPE(AppRender)

    };

}