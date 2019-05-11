#pragma once

struct ModelData
{
public:

    ModelData() = default;

    std::vector<float> positions;
    std::vector<float> textureCoords;
    std::vector<int> indices;

};