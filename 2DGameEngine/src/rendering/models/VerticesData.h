#pragma once


struct VerticesData
{
public:

    VerticesData() = default;

    float* positions;
    float* textureCoords;
    int dataSize;

    int* indices;
    int indexCount;

};

