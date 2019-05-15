#pragma once

#include <functional>
#include <vector>


class BaseEventCallback
{
public:

    virtual void operator()() = 0;

};

template<class T>
class EventCallback : public BaseEventCallback
{
public:

    EventCallback(const T& event, const std::function<void(const T&)>& callback)
        : m_event(event)
        , m_callback(callback)
    {}

    void operator()()
    {
        m_callback(m_event);
    }

private:

    T m_event;
    const std::function<void(const T&)>& m_callback;

};

template<class T>
class CallbackWrapper
{
public:

    std::function<void(const T&)> callback;

};

class EventDispatcher
{
public:

    static EventDispatcher& getInstance()
    {
        return m_instance;
    }

    EventDispatcher(const EventDispatcher&) = delete;
    void operator=(const EventDispatcher&) = delete;

    template<class T>
    void registerCallback(const std::function<void(const T&)>& callback)
    {
        CallbackWrapper<T>& callbackWrapper = getCallbackWrapper<T>();
        callbackWrapper.callback = callback;
    }

    template<class T>
    void queueEvent(const T& event)
    {
        CallbackWrapper<T>& callbackWrapper = getCallbackWrapper<T>();

        if (callbackWrapper.callback)
        {
            m_eventCallbacks.push_back(new EventCallback<T>(event, callbackWrapper.callback));
        }
    }

    void dispatchEvents()
    {
        for (BaseEventCallback* eventCallback : m_eventCallbacks)
        {
            (*eventCallback)();
            delete eventCallback;
        }
        m_eventCallbacks.clear();
    }

private:

    template<class T>
    CallbackWrapper<T>& getCallbackWrapper()
    {
        static CallbackWrapper<T> callbackWrapper = CallbackWrapper<T>();
        return callbackWrapper;
    }

    EventDispatcher() = default;

    static EventDispatcher m_instance;

    std::vector<BaseEventCallback*> m_eventCallbacks;

};