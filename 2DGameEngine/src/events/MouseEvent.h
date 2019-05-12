#pragma once


namespace Engine {

    class Event; // Forward declaration

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(int mouseX, int mouseY)
            : m_mouseX(mouseX), m_mouseY(mouseY) {}
        virtual ~MouseMovedEvent() {}

        EVENT_TYPE(MouseMoved)

    private:
        int m_mouseX;
        int m_mouseY;
        
    };


    class MouseButtonEvent : public Event
    {
    public:
        MouseButtonEvent(int mouseButton)
            : m_mouseButton(mouseButton) {}
        virtual ~MouseButtonEvent() {}

        inline int getButtonCode() const { return m_mouseButton; }

    private:
        int m_mouseButton;

    };


    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int mouseButton)
            : MouseButtonEvent(mouseButton) {}
        virtual ~MouseButtonPressedEvent() {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent :" << getButtonCode();
            return ss.str();
        }

        EVENT_TYPE(MouseButtonPressed)

    };


    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int mouseButton)
            : MouseButtonEvent(mouseButton) {}
        virtual ~MouseButtonReleasedEvent() {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent :" << getButtonCode();
            return ss.str();
        }

        EVENT_TYPE(MouseButtonReleased)

    };

}