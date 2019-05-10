#pragma once


struct VerticesData
{
public:

    VerticesData() = default;
    VerticesData(float* const positions, float* const textureCoords, int dataSize, int* indices, int indexCount);

    int dataSize;
    float* positions;
    float* textureCoords;

    int indexCount;
    int* indices;

};

