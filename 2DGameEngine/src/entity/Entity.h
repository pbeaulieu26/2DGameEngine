#pragma once


namespace Engine {

    typedef int EntityId;

    class ENGINE_API Entity
    {

    public:

        const EntityId getId() const { return m_id; }

    private:

        EntityId m_id;
    };

}

