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
    }


    void Scene::addEntity(std::shared_ptr<Entity> entity)
    {
        m_entities[entity->getId()] = entity;
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