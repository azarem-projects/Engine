#include "core.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void api::core::log(const std::string& data)
{
    std::cout << data << '\n';
}

void api::core::initEverything()
{
    glewExperimental = GL_TRUE;
    glewInit();
    glfwInit();
}
