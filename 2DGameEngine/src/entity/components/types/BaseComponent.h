#pragma once


namespace Engine {

    typedef int ComponentId;

    class ENGINE_API BaseComponent
    {

    public:

        inline void activate() { m_isActivated = true; };
        inline void deactivate() { m_isActivated = false; };

        inline bool isActivated() { return m_isActivated; }

    protected:

        BaseComponent() { m_isActivated = true; };

    private:

        bool m_isActivated;

    };

}

