#include "Core.h"

#include <debug/Log.h>
#include "environment/Window.h"

namespace api
{
    namespace core
    {
        void Core::init()
        {
            // debug::Log::init();
            env::Window::init();
        }
    }
}