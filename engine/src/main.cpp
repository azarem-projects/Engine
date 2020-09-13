#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>

#include <core/core.h>

int main()
{
    glewExperimental = GL_TRUE;
    glewInit();
    glfwInit();
    Assimp::Importer* importer = new Assimp::Importer();

    api::core::initEverything();

    return 0;
}