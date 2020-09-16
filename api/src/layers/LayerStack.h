#pragma once

#include <vector>

#include "Layer.h"
#include "architecture/Macros.h"

namespace api
{
    namespace layers
    {
        class LayerStack
        {
        private:
            std::vector<Layer*> layers;

        public:
            void pushLayer(Layer* layer);
            std::vector<Layer*>& getLayers();

            void init();
            void update();
        };

        LayerStack* createLayerStack();
    }
}