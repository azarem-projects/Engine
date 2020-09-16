#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

#include <debug/Log.h>

#include "architecture/Macros.h"

namespace api
{
    namespace env
    {
        struct WindowConfig
        {
            int width = 1920;
            int height = 1080;

            std::string title = "OpenGL";

            bool fullscreen = false;
        };

        static WindowConfig windowConfig;

        class Window
        {
        SINGLETON(Window, [](auto&) {})

        private:
            GLFWwindow* window;

        public:
            static void init();
            static bool shouldClose();
            static void clear();
            static void swapBuffers();
        };
    }
}
