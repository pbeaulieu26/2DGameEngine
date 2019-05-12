#pragma once

#include "Event.h"


namespace Engine {

    typedef std::function<void(const Event& event)> EventFn;
    typedef std::unordered_map<EventType, EventFn> EventTypeToFuncMap;


    class EventDispatcher
    {

    public:
        EventDispatcher();
        virtual ~EventDispatcher();

        void dispatchEvent(const Event& event);

        void registerCallback(EventType eventType, EventFn eventCallback);

    private:
        EventTypeToFuncMap m_eventTypeToFuncMap;

    };

}
