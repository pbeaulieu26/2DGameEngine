#pragma once

#include <glad/glad.h>


class ENGINE_API TextureLoader
{
public:

    TextureLoader() = default;
    virtual ~TextureLoader();

    TextureLoader(const TextureLoader&) = delete;
    void operator=(const TextureLoader&) = delete;

    GLuint loadTexture(const char * fileName);


private:

    std::vector<GLuint> m_textures;

};


