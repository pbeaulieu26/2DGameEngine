#include "pch.h"
#include "rendering/display/DisplayManager.h"
#include "rendering/textures/TextureLoader.h"
#include "rendering/textures/animations/AnimationUpdater.h"
#include "rendering/textures/animations/AnimatedTexturedModel.h"
#include "rendering/models/TexturedModel.h"
#include "rendering/models/loaders/VertexObjectLoader.h"
#include "rendering/renderers/GuiRenderer.h"
#include "rendering/renderers/Renderer2D.h"
#include "rendering/entities/GuiEntity.h"
#include "rendering/entities/Entity.h"
#include "rendering/entities/Camera.h"
#include "rendering/models/ModelData.h"
#include "rendering/models/loaders/ObjFileLoader.h"
#include "Engine.h"

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
    AnimationUpdater animationUpdater;

    ModelData modelData = ObjFileLoader::loadOBJ("res/hex.obj", 4);
    RawModel hex = vertexObjectLoader.loadToVAO(modelData);
    AnimatedTexturedModel animatedTexturedModel{ hex, textureLoader.loadTexture("res/forest_texture.png"), 0, 0, 4, 16 };
    Entity entity1{ animatedTexturedModel.texturedModel, glm::vec2(0.0, 0.0), 0.0, glm::vec2(0.2, 0.2) };
    Entity entity2{ animatedTexturedModel.texturedModel, glm::vec2(0.35, 0.0), 0.0, glm::vec2(0.2, 0.2) };
    std::unordered_map<AnimatedTexturedModel, std::vector<Entity>, AnimatedTexturedModel::Hasher> entities;
    animationUpdater.bindAnimatedTextureData(animatedTexturedModel.animatedTextureData);

    // Game loop

    int counter = 0;

    while (!DisplayManager::isCloseRequested())
    {
        DisplayManager::processInput();

        entities.clear();
        entities[animatedTexturedModel] = std::vector<Entity>{ entity1, entity2 };

        renderer2D.render(entities, camera);

        if (++counter == 6)
        {
            animationUpdater.update();
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
    /*if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.position.x += 0.003f;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.position.x -= 0.003f;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.position.y += 0.003f;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.position.y -= 0.003f;
    }*/
}