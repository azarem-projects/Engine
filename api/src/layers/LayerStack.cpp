#include "LayerStack.h"

namespace api
{
    namespace layers
    {
        void LayerStack::pushLayer(Layer* layer)
        {
            layers.emplace_back(layer);
        }

        std::vector<Layer*>& LayerStack::getLayers()
        {
            return layers;
        }

        void LayerStack::init()
        {
            for (Layer* layer : layers)
            {
                layer->init();
            }
        }

        void LayerStack::update()
        {
            for (Layer* layer : layers)
            {
                layer->update();
            }
        }
    }
}
