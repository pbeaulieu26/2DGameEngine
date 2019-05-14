#include <iostream>

#include <Engine.h>
#include <GLFW/glfw3.h>


class SandBox : public Engine::Application
{
public:
    SandBox() {};
    virtual ~SandBox() {};

    void onMouseButtonPressedEvent(std::unique_ptr<Engine::Event> event) override;
    void onMouseButtonReleasedEvent(std::unique_ptr<Engine::Event> event) override;
    void onMouseMovedEvent(std::unique_ptr<Engine::Event> event) override;

    void onKeyPressedEvent(std::unique_ptr<Engine::Event> event) override;
    void onKeyReleasedEvent(std::unique_ptr<Engine::Event> event) override;
};


Engine::Application* Engine::CreateApplication()
{
    return new SandBox();
}

void SandBox::onMouseButtonPressedEvent(std::unique_ptr<Engine::Event> event)
{
    Engine::MouseButtonPressedEvent* mouseMovedEvent = dynamic_cast<Engine::MouseButtonPressedEvent*>(event.get());
}


void SandBox::onMouseButtonReleasedEvent(std::unique_ptr<Engine::Event> event)
{
    Engine::MouseButtonReleasedEvent* mouseMovedEvent = dynamic_cast<Engine::MouseButtonReleasedEvent*>(event.get());
}


void SandBox::onMouseMovedEvent(std::unique_ptr<Engine::Event> event)
{
    Engine::MouseMovedEvent* mouseMovedEvent = dynamic_cast<Engine::MouseMovedEvent*>(event.get());
}


void SandBox::onKeyPressedEvent(std::unique_ptr<Engine::Event> event)
{
    Engine::KeyPressedEvent* mouseMovedEvent = dynamic_cast<Engine::KeyPressedEvent*>(event.get());
}


void SandBox::onKeyReleasedEvent(std::unique_ptr<Engine::Event> event)
{
    Engine::KeyReleasedEvent* mouseMovedEvent = dynamic_cast<Engine::KeyReleasedEvent*>(event.get());
}

