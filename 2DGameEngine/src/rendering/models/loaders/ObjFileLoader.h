#pragma once

#include "rendering/models/ModelData.h"

class ENGINE_API ObjFileLoader
{
public:

    static ModelData loadOBJ(const std::string& objFileName, int subTextureSize = 1);

private:

    static std::vector<std::string>split(std::string line, char separator);

};

