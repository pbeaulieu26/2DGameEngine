#include "pch.h"
#include "GameObject.h"


namespace Engine {

    GameObject::GameObject()
    {
    }


    GameObject::~GameObject()
    {
        for (auto it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
        {
            delete it->second;
        }

        m_componentMap.clear();
    }

}
