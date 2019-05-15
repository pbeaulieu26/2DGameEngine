#pragma once

#include "Application.h"


extern Engine::Application* Engine::CreateApplication();


int main(int argc, char** argv)
{
    auto app = Engine::CreateApplication();
    LOG_CORE_INFO("Application created");

    app->run();
    delete app;


    LOG_CORE_INFO("Engine terminated");
}
