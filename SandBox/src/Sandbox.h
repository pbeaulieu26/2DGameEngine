#pragma once

#include <Engine.h>


class SandBox : public Engine::Application
{

public:

    SandBox();
    virtual ~SandBox();

    void onMouseButtonPressedEvent(const Engine::MouseButtonPressedEvent& event) override;
    void onMouseButtonReleasedEvent(const Engine::MouseButtonReleasedEvent& event) override;
    void onMouseMovedEvent(const Engine::MouseScrolledEvent& event) override;

    void onKeyPressedEvent(const Engine::KeyPressedEvent& event) override;
    void onKeyReleasedEvent(const Engine::KeyReleasedEvent& event) override;

    void onAppUpdateEvent(const Engine::AppUpdateEvent & event) override;

};