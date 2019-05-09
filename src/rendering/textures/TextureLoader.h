#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <vector>
#include <glad/glad.h>

class TextureLoader
{
public:

    virtual ~TextureLoader();
    GLuint loadTexture(const char * fileName);

private:

    std::vector<GLuint> m_textures;

};

#endif // !TEXTURE_LOADER_H

