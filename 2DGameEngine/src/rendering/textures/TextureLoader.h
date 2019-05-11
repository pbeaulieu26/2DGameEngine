#pragma once

#include <glad/glad.h>


class TextureLoader
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


