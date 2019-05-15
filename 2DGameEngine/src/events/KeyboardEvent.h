#pragma once

#include "pch.h"

namespace Engine {

    class ENGINE_API KeyEvent
    {

    public:

        KeyEvent(int keyCode)
            : m_keyCode(keyCode) {}

        inline int getKeyCode() const { return m_keyCode; }

    private:

        int m_keyCode;

    };


    class ENGINE_API KeyPressedEvent : public KeyEvent
    {

    public:

        KeyPressedEvent(int keyCode)
            :KeyEvent(keyCode) {}
        virtual ~KeyPressedEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << getKeyCode();
            return ss.str();
        }

    };


    class ENGINE_API KeyReleasedEvent : public KeyEvent
    {

    public:

        KeyReleasedEvent(int keyCode)
            : KeyEvent(keyCode) {}
        virtual ~KeyReleasedEvent() {}

        std::string toString() const
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << getKeyCode();
            return ss.str();
        }

    };

}