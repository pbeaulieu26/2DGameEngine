#include "pch.h"
#include "World.h"


namespace Engine {

    World::World()
        : m_currentScene(nullptr)
    {
    }


    std::shared_ptr<Scene> World::createScene(std::string sceneName)
    {
        m_scenes[sceneName] = std::make_shared<Scene>(sceneName);
        return m_scenes[sceneName];
    }


    void World::deleteScene(std::string sceneName)
    {
        auto it = m_scenes.find(sceneName);
        if (it != m_scenes.end())
        {
            it->second.reset();
            m_scenes.erase(it);

            if (m_currentScene->getName() == sceneName)
            {
                if (m_scenes.size() == 1)
                {
                    m_currentScene = nullptr;
                }
                else
                {
                    m_currentScene = m_scenes.begin()->second;
                }
            }
        }
    }


    void World::setCurrentScene(std::string sceneName)
    {
        auto it = m_scenes.find(sceneName);
        if (it != m_scenes.end())
        {
            m_currentScene = it->second;
        }
    }


    std::shared_ptr<Scene> World::getCurrentScene()
    {
        return m_currentScene;
    }

}
