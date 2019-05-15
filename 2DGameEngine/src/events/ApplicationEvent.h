#pragma once

#include "pch.h"


namespace Engine {

    class ENGINE_API AppTickEvent
    {
    public:
        AppTickEvent() {}
        virtual ~AppTickEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "AppTickEvent";
            return ss.str();
        }

    };


    class ENGINE_API AppUpdateEvent
    {
    public:
        AppUpdateEvent() {}
        virtual ~AppUpdateEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "AppUpdateEvent";
            return ss.str();
        }

    };


    class ENGINE_API AppRenderEvent
    {
    public:
        AppRenderEvent() {}
        virtual ~AppRenderEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "AppRenderEvent: ";
            return ss.str();
        }

    };

}