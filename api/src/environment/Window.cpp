#include "Window.h"

namespace api
{
    namespace env
    {
        void Window::init()
        {
            Window& instance = getInstance();

            glfwInit();

            glfwDefaultWindowHints();
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

            instance.window = glfwCreateWindow(
                windowConfig.width,
                windowConfig.height,
                windowConfig.title.c_str(),
                windowConfig.fullscreen ? glfwGetPrimaryMonitor() : NULL,
                NULL
            );

            glfwMakeContextCurrent(instance.window);
            glfwSwapInterval(1);

            glewInit();
            glewExperimental = GL_TRUE;

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);

            glEnable(GL_DEPTH_TEST);

            glClearColor(0, 0, 0, 1);

            glfwShowWindow(instance.window);
        }

        bool Window::shouldClose()
        {
            Window& instance = getInstance();

            return glfwWindowShouldClose(instance.window);
        }

        void Window::clear()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::swapBuffers()
        {
            Window& instance = getInstance();

            glfwSwapBuffers(instance.window);
            glfwPollEvents();
        }
    }
}
