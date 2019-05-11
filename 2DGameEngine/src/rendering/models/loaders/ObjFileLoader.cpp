#include "pch.h"
#include "ObjFileLoader.h"
#include "rendering/models/Vertex.h"

#include <sstream>
#include <fstream>


ModelData ObjFileLoader::loadOBJ(const std::string& objFileName, int subTextureSize)
{
    std::ifstream objFile(objFileName);

    ModelData modelData;

    std::vector<Vertex> vertices;
    std::vector<glm::vec2> textures;
    
    std::string line;
    while (std::getline(objFile, line))
    {
        std::vector<std::string> strings = split(line, ' ');

        if (strings.size() > 0)
        {
            if (strings[0] == "v" && strings.size() == 3)
            {
                vertices.push_back(Vertex{ std::stof(strings[1]), std::stof(strings[2]) });
            }
            else if (strings[0] == "vt" && strings.size() == 3)
            {
                textures.push_back(glm::vec2{ std::stof(strings[1]), std::stof(strings[2]) });
            }
            else if (strings[0] == "f" && strings.size() == 4)
            {
                for (int i = 1; i < 4; ++i)
                {
                    std::vector<std::string> indiceStrings = split(strings[i], '/');
                    int index = std::stof(indiceStrings[0]);
                    Vertex& vertex = vertices[index];
                    vertex.textureIndex = std::stof(indiceStrings[1]);
                    modelData.indices.push_back(index);
                }
            }
        }
    }

    // Currently we are not taking into account a single vertex could have multiple texture coordinates.

    for (const Vertex& vertex : vertices)
    {
        modelData.positions.push_back(vertex.x);
        modelData.positions.push_back(vertex.y);
        const glm::vec2& texture = textures[vertex.textureIndex];
        modelData.textureCoords.push_back(texture.x / subTextureSize);
        modelData.textureCoords.push_back(texture.y / subTextureSize);
    }

    return modelData;
}

std::vector<std::string> ObjFileLoader::split(std::string line, char separator)
{
    std::vector<std::string> result;
    std::istringstream iss(line);
    while (iss.good())
    {
        std::string substr;
        std::getline(iss, substr, separator);
        result.push_back(substr);
    }
    return result;
}
