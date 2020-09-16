#pragma once

#include <string>

#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

namespace api
{
    namespace files
    {
        std::string readFile(const std::string& path);
    }
}
