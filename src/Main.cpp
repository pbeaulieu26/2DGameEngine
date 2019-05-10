#include "pch.h"
#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/models/VertexObjectLoader.h"
#include "rendering/renderers/GuiRenderer.h"
#include "rendering/renderers/Renderer2D.h"
#include "rendering/entities/GuiEntity.h"
#include "rendering/entities/Entity.h"
#include "rendering/entities/Camera.h"
#include "rendering/models/VerticesData.h"
#include "engine/Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void processInput(GLFWwindow* window);

namespace rect
{
    float positions[] = { -1, 1, -1, -1, 1, -1, 1, 1 };
    float textureCoords[] = { 0, 1, 1, 0, 1, 0, 0, 1 };
    int indices[] = { 0, 1, 2, 0, 2, 3 };
}

namespace hex
{
    float side = sqrt(3.0f) / 2.0f;
    float positions[] = { -side, 0.5, -side, -0.5, 0, -1, side, -0.5, side, 0.5, 0, 1 };
    float textureCoords[] = { 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0 };
    int indices[] = { 0, 1, 2, 0, 2, 5, 2, 3, 5, 3, 4, 5 };
}

int main()
{
    Engine::Log::Init();
    LOG_INFO("Logger initialized");

    int code = DisplayManager::createDisplay(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (code != MANAGER_SUCCESS)
    {
        return code;
    }

    DisplayManager::registerInputCallback(processInput);

    // Gui rendering initialization

    VertexObjectLoader vertexObjectLoader;
    GuiRenderer guiRenderer(vertexObjectLoader);

    TextureLoader textureLoader;
    GuiEntity gui{ textureLoader.loadTexture("res/red_texture.png"), glm::vec2(-0.5, -0.5), glm::vec2(0.5, 0.5) };
    std::vector<GuiEntity> guis{ gui };

    // Entity rendering initialization

    Renderer2D renderer2D;
    Camera camera{ glm::vec2(0.4, 0.0), 0.1f };

    VerticesData verticesDataHex{ hex::positions, hex::textureCoords, 12, hex::indices, 12 };
    RawModel hex = vertexObjectLoader.loadToVAO(verticesDataHex);
    TexturedModel texturedModel(hex, textureLoader.loadTexture("res/dual_texture.png"));
    Entity entity{ texturedModel, glm::vec2(0.0, 0.0), 0.0, glm::vec2(0.2, 0.2) };
    std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher> entities;
    entities[texturedModel] = std::vector<Entity>{ entity };

    // Game loop

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();

        guiRenderer.render(guis);
        renderer2D.render(entities, camera);

        DisplayManager::updateDisplay();
    }

    DisplayManager::closeDisplay();

    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}