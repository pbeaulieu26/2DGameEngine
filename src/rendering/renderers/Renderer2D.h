#ifndef RENDERER_2D_H
#define RENDERER_2D_H

#include "rendering/shaders/Shader2D.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/textures/Texture.h"

class Renderer2D
{
public:

    explicit Renderer2D(VertexObjectLoader& vertexObjectLoader);

    void render(const std::vector<Texture>& textures);

private:

    void initializeGlContext();

private:

    RawModel m_quad;
    Shader2D m_shader;

};

#endif // !RENDERER_2D_H

