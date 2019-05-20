#include "pch.h"
#include "Sandbox.h"
#include "ExampleEntity.h"


Engine::Application* Engine::CreateApplication()
{
    return new SandBox();
}


SandBox::SandBox()
{
    std::shared_ptr<Engine::Scene> scene = Engine::World::getInstance().createScene("main");
    LOG_INFO("Created scene name: {0}", scene->getName());

    m_player = std::make_shared<ExampleEntity>();
    LOG_INFO("Created entity id: {0}", m_player->getId());

    std::shared_ptr<ExampleEntity> entity1 = std::make_shared<ExampleEntity>();
    LOG_INFO("Created entity id: {0}", entity1->getId());

    std::shared_ptr<ExampleEntity> entity2 = std::make_shared<ExampleEntity>();
    LOG_INFO("Created entity id: {0}", entity2->getId());

    scene->addEntity(m_player);
    scene->addEntity(entity1);
    scene->addEntity(entity2);

    Engine::World::getInstance().setCurrentScene(scene->getName());
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
    // Game logic to be done every frame
    // ...
}

