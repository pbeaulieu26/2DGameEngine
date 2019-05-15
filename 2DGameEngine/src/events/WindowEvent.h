#pragma once

#include "pch.h"
#include "rendering/display/WindowSize.h"


namespace Engine {

    class ENGINE_API WindowCloseEvent
    {

    public:

        WindowCloseEvent() {}
        virtual ~WindowCloseEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "WindowCloseEvent";
            return ss.str();
        }

    };


    class ENGINE_API WindowFocusEvent
    {

    public:

        WindowFocusEvent() {}
        virtual ~WindowFocusEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "WindowFocusEvent";
            return ss.str();
        }

    };


    class ENGINE_API WindowLostFocusEvent
    {

    public:

        WindowLostFocusEvent() {}
        virtual ~WindowLostFocusEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "WindowLostFocusEvent";
            return ss.str();
        }

    };


    class ENGINE_API WindowResizeEvent
    {

    public:

        WindowResizeEvent(const WindowSize& size) 
            : m_size(size) {}
        virtual ~WindowResizeEvent() {}

        inline WindowSize getSize() const { return m_size; }

        std::string toString() const
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << getSize().width << ", " << getSize().height;
            return ss.str();
        }

    private:

        WindowSize m_size;

    };

}