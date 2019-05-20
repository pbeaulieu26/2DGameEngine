#include "Sandbox.h"


Engine::Application* Engine::CreateApplication()
{
    return new SandBox();
}

SandBox::SandBox()
{
}

SandBox::~SandBox()
{
}

void SandBox::onMouseButtonPressedEvent(const Engine::MouseButtonPressedEvent& event)
{
}


void SandBox::onMouseButtonReleasedEvent(const Engine::MouseButtonReleasedEvent& event)
{
}


void SandBox::onMouseMovedEvent(const Engine::MouseScrolledEvent& event)
{
    
}


void SandBox::onKeyPressedEvent(const Engine::KeyPressedEvent& event)
{
    if (event.getKeyCode() == Engine::KEY_ESCAPE)
    {
        close();
    }
    
}


void SandBox::onKeyReleasedEvent(const Engine::KeyReleasedEvent& event)
{
}


void SandBox::onAppUpdateEvent(const Engine::AppUpdateEvent & event)
{
    LOG_CORE_WARN("Unhandled : {0}", event.toString());
}

