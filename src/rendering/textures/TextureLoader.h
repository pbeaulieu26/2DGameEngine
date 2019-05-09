#pragma once

#include <glad/glad.h>


class TextureLoader
{
public:

    virtual ~TextureLoader();
    GLuint loadTexture(const char * fileName);

private:

    std::vector<GLuint> m_textures;

};


