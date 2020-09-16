#include "app.h"

#include "core.h"
#include "window.h"

namespace api
{
    namespace core
    {
        void App::run()
        {
            api::core::Core::init();

            while (!api::core::Window::shouldClose())
            {
                api::core::Window::clear();
                
                api::core::Window::swapBuffers();
            }
        }
    }
}