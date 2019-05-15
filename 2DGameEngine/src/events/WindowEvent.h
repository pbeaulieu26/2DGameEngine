#pragma once

#include "pch.h"
#include "rendering/display/WindowSize.h"


namespace Engine {

    class ENGINE_API WindowCloseEvent
    {
    public:
        WindowCloseEvent() {}
        virtual ~WindowCloseEvent() {}

    };

    class ENGINE_API WindowFocusEvent
    {
    public:
        WindowFocusEvent() {}
        virtual ~WindowFocusEvent() {}

    };

    class ENGINE_API WindowLostFocusEvent
    {
    public:
        WindowLostFocusEvent() {}
        virtual ~WindowLostFocusEvent() {}

    };

    class ENGINE_API WindowResizeEvent
    {
    public:
        WindowResizeEvent(const WindowSize& size) 
            : size(size) {}
        virtual ~WindowResizeEvent() {}

    private:
        WindowSize size;

    };

}