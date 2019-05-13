#pragma once

#include "Event.h"


namespace Engine {

    typedef std::unordered_map<EventType, EventFn> EventTypeToFuncMap;

    class EventDispatcher
    {

    public:
        EventDispatcher();
        virtual ~EventDispatcher();

        void dispatchEvent(std::unique_ptr<Event> event);

        void registerCallback(EventType eventType, EventFn eventCallback);

    private:
        EventTypeToFuncMap m_eventTypeToFuncMap;

    };

}
