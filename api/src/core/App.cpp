#include "App.h"

#include "core/Core.h"
#include "environment/Window.h"

extern api::layers::LayerStack* api::layers::createLayerStack();

namespace api
{
    namespace core
    {
        void App::run()
        {
            core::Core::init();

            layerStack = layers::createLayerStack();

            layerStack->init();

            while (!env::Window::shouldClose())
            {
                env::Window::clear();

                layerStack->update();

                env::Window::swapBuffers();
            }
        }
    }
}
