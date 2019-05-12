#include "pch.h"
#include "EventDispatcher.h"


namespace Engine {

    EventDispatcher::EventDispatcher()
    {
    }


    EventDispatcher::~EventDispatcher()
    {
    }

    void EventDispatcher::dispatchEvent(const Event& event)
    {
        auto iter = m_eventTypeToFuncMap.find(event.getEventType());
        if (iter != m_eventTypeToFuncMap.end())
        {
            (iter->second)(event);
        }
    }

    void EventDispatcher::registerCallback(EventType eventType, EventFn eventCallback)
    {
        m_eventTypeToFuncMap[eventType] = eventCallback;
    }

}