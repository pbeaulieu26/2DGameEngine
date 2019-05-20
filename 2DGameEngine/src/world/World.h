#pragma once

#include "scene/Scene.h"


namespace Engine {

    class ENGINE_API World
    {

    public:

        World(World const&) = delete;
        void operator=(World const&) = delete;

        static World& getInstance()
        {
            static World instance;
            
            return instance;
        }

        std::shared_ptr<Scene> createScene(std::string sceneName);

        void deleteScene(std::string sceneName);

        void setCurrentScene(std::string sceneName);

        std::shared_ptr<Scene> getCurrentScene();

    private:

        World();

        std::shared_ptr<Scene> m_currentScene;
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;

    };

}
