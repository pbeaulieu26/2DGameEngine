#include "pch.h"
#include "VerticesData.h"


VerticesData::VerticesData(float* const positions, float* const textureCoords, int dataSize, int* indices, int indexCount)
    : positions(positions)
    , textureCoords(textureCoords)
    , dataSize(dataSize)
    , indices(indices)
    , indexCount(indexCount)
{
}
