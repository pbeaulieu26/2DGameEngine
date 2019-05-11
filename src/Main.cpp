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

#include <chrono>
#include <thread>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void processInput(GLFWwindow* window);

namespace
{
    Camera camera{ glm::vec2(0.4, 0.0), 0.0f };
}

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
    float textureCoords[] = { 0.5 - side / 2, 0.75, 0.5 - side / 2, 0.25, 0.5, 0, 0.5 + side / 2, 0.25, 0.5 + side / 2, 0.75, 0.5, 1 };
    int indices[] = { 0, 1, 2, 0, 2, 5, 2, 3, 5, 3, 4, 5 };
}

namespace animatedHex
{
    float textureCoords[12];
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

    // Entity rendering initialization

    Renderer2D renderer2D;
    TextureLoader textureLoader;
    VertexObjectLoader vertexObjectLoader;

    float textureCoords[12];

    for (int i = 0; i < 12; i++)
    {
        textureCoords[i] = hex::textureCoords[i] / 4;
    }

    VerticesData verticesDataHex{ hex::positions, textureCoords, 12, hex::indices, 12 };
    RawModel hex = vertexObjectLoader.loadToVAO(verticesDataHex);
    TexturedModel texturedModel{ hex, textureLoader.loadTexture("res/forest_texture.png"), 0, 0, 4, 16 };
    Entity entity1{ texturedModel, glm::vec2(0.0, 0.0), 0.0, glm::vec2(0.2, 0.2) };
    Entity entity2{ texturedModel, glm::vec2(0.35, 0.0), 0.0, glm::vec2(0.2, 0.2) };
    std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModel::Hasher> entities;

    // Game loop

    int counter = 0;

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();

        entities.clear();
        entities[texturedModel] = std::vector<Entity>{ entity1, entity2 };

        renderer2D.render(entities, camera);

        if (++counter == 6)
        {
            texturedModel.animatedTextureData.nextSubTexture();
            counter = 0;
        }

        DisplayManager::updateDisplay();

        std::this_thread::sleep_for(std::chrono::milliseconds(15));
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
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.position.x += 0.003;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.position.x -= 0.003;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.position.y += 0.003;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.position.y -= 0.003;
    }
}