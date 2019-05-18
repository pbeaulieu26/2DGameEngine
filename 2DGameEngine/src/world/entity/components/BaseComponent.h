#pragma once


namespace Engine {

    class ENGINE_API BaseComponent
    {

        inline void activate() { m_isActivated = true; };
        inline void deactivate() { m_isActivated = false; };

        inline bool isActivated() { return m_isActivated; }

    protected:

        BaseComponent() { m_isActivated = true; };

    private:

        bool m_isActivated;

    };

    #define COMPONENT_INFO(type) static std::size_t getStaticId() { return std::hash<std::string>{}(type); };

}

