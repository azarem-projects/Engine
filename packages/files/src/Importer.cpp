#include "Importer.h"

// #include <debug/Log.h>

std::string api::files::readFile(const std::string& path)
{
    std::string accumulator = "";

    std::ifstream fileStream(path, std::ios::in);

    if (!fileStream.is_open()) {
        // ENGINE_ERROR("Could not read file {0}. File does not exist.", path);
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        getline(fileStream, line);
        accumulator.append(line + "\n");
    }

    fileStream.close();

    return accumulator.c_str();
}