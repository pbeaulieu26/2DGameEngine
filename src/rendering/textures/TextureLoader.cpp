#include "pch.h"
#include "TextureLoader.h"
#include "rendering/stb/stb_image.h"


TextureLoader::~TextureLoader()
{
    for (GLuint texture : m_textures)
    {
        glDeleteTextures(1, &texture);
    }
}

GLuint TextureLoader::loadTexture(const char * fileName)
{
    GLuint texture;
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(false);

    unsigned char *data = stbi_load(fileName, &width, &height, &nrChannels, STBI_rgb);
    if (data)
    {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -0.4f);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);
        m_textures.push_back(texture);
        stbi_image_free(data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    
    return texture;
}