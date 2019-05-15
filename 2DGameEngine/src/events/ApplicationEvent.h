#pragma once

#include "pch.h"


namespace Engine {

    class ENGINE_API AppTickEvent
    {
    public:
        AppTickEvent() {}
        virtual ~AppTickEvent() {}

    };


    class ENGINE_API AppUpdateEvent
    {
    public:
        AppUpdateEvent() {}
        virtual ~AppUpdateEvent() {}

    };


    class ENGINE_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}
        virtual ~AppRenderEvent() {}

        EVENT_TYPE(AppRender)

    };

}