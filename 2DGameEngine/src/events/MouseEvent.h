#pragma once

#include "pch.h"

namespace Engine {

    class ENGINE_API MouseMovedEvent
    {

    public:

        MouseMovedEvent(double mouseX, double mouseY)
            : m_mouseX(mouseX), m_mouseY(mouseY) {}
        virtual ~MouseMovedEvent() {}

        inline double getMouseX() const { return m_mouseX; }
        inline double getMouseY() const { return m_mouseY; }

        std::string toString() const
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << getMouseX() << " " << getMouseY();
            return ss.str();
        }

    private:

        double m_mouseX;
        double m_mouseY;
        
    };


    class ENGINE_API MouseButtonEvent
    {

    public:

        MouseButtonEvent(int mouseButton)
            : m_mouseButton(mouseButton) {}
        virtual ~MouseButtonEvent() {}

        inline int getButtonCode() const { return m_mouseButton; }

    private:

        int m_mouseButton;

    };


    class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
    {

    public:

        MouseButtonPressedEvent(int mouseButton)
            : MouseButtonEvent(mouseButton) {}
        virtual ~MouseButtonPressedEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << getButtonCode();
            return ss.str();
        }

    };


    class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {

    public:

        MouseButtonReleasedEvent(int mouseButton)
            : MouseButtonEvent(mouseButton) {}
        virtual ~MouseButtonReleasedEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << getButtonCode();
            return ss.str();
        }

    };


    class ENGINE_API MouseScrolledEvent
    {

    public:

        MouseScrolledEvent(double xOffset, double yOffset)
            : m_xOffset(xOffset), m_yOffset(yOffset) {}

        inline double GetXOffset() const { return m_xOffset; }
        inline double GetYOffset() const { return m_yOffset; }

        std::string toString() const
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

    private:

        double m_xOffset, m_yOffset;

    };

}