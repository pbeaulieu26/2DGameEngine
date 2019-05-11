#pragma once


struct ENGINE_API VerticesData
{
public:

    VerticesData() = default;

    float* positions;
    float* textureCoords;
    int dataSize;

    int* indices;
    int indexCount;

};

