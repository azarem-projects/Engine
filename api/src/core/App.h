#pragma once

#include "layers/LayerStack.h"
#include "layers/Layer.h"

namespace api
{
    namespace core
    {
        class App
        {
        private:
            layers::LayerStack* layerStack;
            
        public:
            void run();
        };

        App* createApp();
    }
}