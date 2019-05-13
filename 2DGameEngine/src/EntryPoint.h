#pragma once

#include "Application.h"
#include "Log.h"


extern Engine::Application* Engine::CreateApplication();


int main(int argc, char** argv)
{
    Engine::Log::Init();
    LOG_CORE_INFO("Logger initialized");

    auto app = Engine::CreateApplication();
    LOG_CORE_INFO("Application created");

    app->run();
    delete app;


    LOG_CORE_INFO("Engine terminated");
}
