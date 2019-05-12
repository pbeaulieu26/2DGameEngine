#pragma once


namespace Engine {

    class Event; // Forward declaration

    class KeyEvent : public Event
    {
    public:
        KeyEvent(int keyCode)
            : m_keyCode(keyCode) {}

        inline int getKeyCode() const { return m_keyCode; }

    private:
        int m_keyCode;
    };


    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode)
            :KeyEvent(keyCode) {}
        virtual ~KeyPressedEvent() {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << getKeyCode();
            return ss.str();
        }

        EVENT_TYPE(KeyPressed)

    };


    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keyCode)
            : KeyEvent(keyCode) {}
        virtual ~KeyReleasedEvent() {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << getKeyCode();
            return ss.str();
        }

        EVENT_TYPE(KeyReleased)

    };

}