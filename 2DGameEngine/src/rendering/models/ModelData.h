#pragma once

struct ENGINE_API ModelData
{
public:

    ModelData() = default;

    std::vector<float> positions;
    std::vector<float> textureCoords;
    std::vector<int> indices;

};