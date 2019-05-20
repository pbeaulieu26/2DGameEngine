#include "pch.h"
#include "Scene.h"
#include "core/Core.h"


namespace Engine {

    Scene::Scene(std::string name)
        : m_name(name)
    {
    }


    Scene::~Scene()
    {
        for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
        {
            it->second.reset();
        }

        m_entities.clear();
    }


    void Scene::addEntity(std::unique_ptr<Entity> entity)
    {
        m_entities[entity->getId()] = std::move(entity);
    }


    void Scene::removeEntity(int entityId)
    {
        auto it = m_entities.find(entityId);
        if (it != m_entities.end())
        {
            it->second.reset();
            m_entities.erase(it);
        }
    }

}