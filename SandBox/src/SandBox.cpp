#include <iostream>

#include <Engine.h>


class SandBox : public Engine::Application
{
public:
    SandBox() {};
    virtual ~SandBox() {};
};


Engine::Application* Engine::CreateApplication()
{
    return new SandBox();
}